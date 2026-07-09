/* eslint-disable no-console */
import { execSync } from 'child_process';
import { readdirSync, existsSync, statSync } from 'fs';
import { join, dirname } from 'path';

const args = process.argv.slice(2);

if (args.length === 0) {
  console.error('\n❌ Uso incorrecto.');
  console.log('💡 Uso esperado: pnpm bench <ruta-al-ejercicio>');
  console.log('   Ejemplo:      pnpm bench challenges/leetcode/two-sum\n');
  process.exit(1);
}

let targetDir = args[0];

if (!existsSync(targetDir)) {
  console.error(`\n❌ Error: La ruta '${targetDir}' no existe.\n`);
  process.exit(1);
}

if (statSync(targetDir).isFile()) {
  targetDir = dirname(targetDir);
}

const files = readdirSync(targetDir);

console.log(`\n🚀 Iniciando análisis de rendimiento para: ${targetDir}\n`);

function detectLanguage() {
  if (files.some((f) => f.endsWith('.cpp'))) return 'C++';
  if (files.some((f) => f.endsWith('.py'))) return 'Python';
  if (files.some((f) => f.endsWith('.ts'))) return 'TypeScript';
  if (files.some((f) => f.endsWith('.rs'))) return 'Rust';
  if (files.some((f) => f.endsWith('.go'))) return 'Go';
  if (files.some((f) => f.endsWith('.java'))) return 'Java';
  return 'Desconocido';
}

function runBenchmark(command: string, buildCommand?: string) {
  if (buildCommand) {
    console.log(`🛠️  Compilando (con optimizaciones)...`);
    try {
      execSync(buildCommand, { stdio: 'ignore' });
    } catch (e) {
      console.error('❌ Error de compilación.');
      process.exit(1);
    }
  }

  console.log(`⏱️  Midiendo tiempo y uso máximo de memoria (RSS)...`);

  // Usamos el comando binario time del sistema operativo que extrae el uso de memoria RAM
  const isMac = process.platform === 'darwin';
  const timeFlag = isMac ? '-l' : '-v';
  const timeBinary = '/usr/bin/time';

  if (!existsSync(timeBinary)) {
    console.warn(
      `⚠️  No se encontró ${timeBinary}. Se requiere para medir memoria de hardware nativo.`
    );
    process.exit(1);
  }

  try {
    // Redirigimos la salida normal (stdout) a /dev/null y procesamos los metadatos (stderr)
    const output = execSync(`${timeBinary} ${timeFlag} sh -c "${command} > /dev/null" 2>&1`, {
      encoding: 'utf8',
    });

    let memoryKb = 0;
    let timeSec = 0;

    if (isMac) {
      const memMatch = output.match(/(\d+)\s+maximum resident set size/);
      if (memMatch) memoryKb = parseInt(memMatch[1], 10) / 1024;

      const timeMatch = output.match(/(\d+\.\d+)\s+user/);
      if (timeMatch) timeSec = parseFloat(timeMatch[1]);
    } else {
      const memMatch = output.match(/Maximum resident set size \(kbytes\):\s+(\d+)/);
      if (memMatch) memoryKb = parseInt(memMatch[1], 10);

      const timeMatch = output.match(/User time \(seconds\):\s+([\d.]+)/);
      if (timeMatch) timeSec = parseFloat(timeMatch[1]);

      // Si fue demasiado rápido para User Time, usamos Wall clock time
      if (timeSec === 0) {
        const wallMatch = output.match(
          /Elapsed \(wall clock\) time \(h:mm:ss or m:ss\):\s+([0-9:.]+)/
        );
        if (wallMatch) {
          const parts = wallMatch[1].split(':');
          if (parts.length === 2) timeSec = parseFloat(parts[0]) * 60 + parseFloat(parts[1]);
          else if (parts.length === 3)
            timeSec =
              parseFloat(parts[0]) * 3600 + parseFloat(parts[1]) * 60 + parseFloat(parts[2]);
        }
      }
    }

    const memoryMb = (memoryKb / 1024).toFixed(2);
    const timeMs = (timeSec * 1000).toFixed(2);

    console.log(`\n✅ Resultados de Benchmark:`);
    console.log(`   - Lenguaje detectado: ${detectLanguage()}`);
    console.log(`   - ⚡ Tiempo de CPU: ${timeMs} ms`);
    console.log(`   - 🧠 Memoria máxima (RAM): ${memoryMb} MB\n`);
  } catch (e: any) {
    console.error('❌ Error en ejecución del benchmark.');
    if (e.stdout) console.error(e.stdout.toString());
    process.exit(1);
  }
}

const binName = 'temp_bench_bin';

try {
  if (files.includes('test.cpp') || files.includes('main.cpp')) {
    const cppFile = files.includes('test.cpp') ? 'test.cpp' : 'main.cpp';
    runBenchmark(`./${binName}`, `g++ -O3 ${join(targetDir, cppFile)} -o ${binName}`);
  } else if (files.includes('main.py')) {
    runBenchmark(`python3 ${join(targetDir, 'main.py')}`);
  } else if (files.includes('main.rs')) {
    runBenchmark(`./${binName}`, `rustc -O --test ${join(targetDir, 'main.rs')} -o ${binName}`);
  } else if (files.includes('main.go') || files.some((f) => f.endsWith('_test.go'))) {
    runBenchmark(`./${binName}`, `cd ${targetDir} && go test -c -o ../../${binName}`);
  } else if (files.some((f) => f.endsWith('Test.java'))) {
    const testFile = files.find((f) => f.endsWith('Test.java'));
    runBenchmark(
      `java -ea -cp ${targetDir} ${testFile?.replace('.java', '')}`,
      `javac ${join(targetDir, '*.java')}`
    );
  } else if (
    files.includes('index.bench.ts') ||
    files.includes('index.ts') ||
    files.includes('index.test.ts')
  ) {
    // Si queremos datos ICPC de memoria para JS/TS, Vitest Bench se queda corto,
    // así que ejecutamos nativamente el test o index y capturamos hardware real.
    const tsFile = files.includes('index.bench.ts')
      ? 'index.bench.ts'
      : files.includes('index.test.ts')
        ? 'index.test.ts'
        : 'index.ts';
    console.log(
      '📌 TypeScript detectado. Ejecutando en Node.js (V8) para capturar memoria real...'
    );
    runBenchmark(`npx tsx ${join(targetDir, tsFile)}`);
  } else {
    console.error(
      '\n❌ No se encontró ningún archivo principal soportado para benchmarking en esta carpeta.\n'
    );
  }
} finally {
  if (existsSync(binName)) {
    execSync(`rm -f ${binName}`);
  }
}
