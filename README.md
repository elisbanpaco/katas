# Katas - Code Forge

Laboratorio personal de programación y ejercicios de código con soporte de nivel competitivo (ICPC).

## Estructura del Proyecto

```text
katas/
├── challenges/             # Ejercicios y problemas
│   ├── leetcode/           # Problemas de LeetCode
│   ├── atcoder/            # Problemas de AtCoder
│   └── algoritmos/         # Algoritmos y ejercicios clásicos
├── scripts/                # Utilidades y generadores
│   ├── generate/           # Scripts de generación de boilerplate
│   └── bench.ts            # Motor de benchmarking nativo
├── .github/workflows/      # CI/CD con GitHub Actions
└── vitest.config.ts        # Configuración de tests
```

## Tech Stack

- **Lenguajes Soportados**: TypeScript, Python, C++, Java, Rust, Go.
- **Testing**: Vitest (TS), Unittest (Python), CAssert (C++), Aserciones nativas (Java), Rust Tests, Go Tests.
- **Benchmarking**: Script personalizado con `/usr/bin/time` para medir métricas de CPU y RAM (RSS).
- **Herramientas**: ESLint, Prettier, Husky, lint-staged.

## Scripts Disponibles

| Comando                             | Descripción                                         |
| ----------------------------------- | --------------------------------------------------- |
| `pnpm new`                          | Genera la estructura de un nuevo ejercicio          |
| `pnpm bench <ruta>`                 | Ejecuta un análisis de rendimiento (CPU/RAM) nativo |
| `pnpm test`                         | Ejecuta las pruebas unitarias (Vitest)              |
| `pnpm test:coverage`                | Ejecuta pruebas con coverage (Vitest)               |
| `pnpm lint` / `pnpm lint:fix`       | Ejecuta / Corrige reglas de ESLint                  |
| `pnpm format` / `pnpm format:check` | Formatea / Verifica el formato con Prettier         |
| `pnpm typecheck`                    | Verifica tipos de TypeScript                        |

## Uso del Generador

Para crear un nuevo ejercicio con testing integrado, ejecuta:

```bash
pnpm new
```

Selecciona el lenguaje (TS, Python, C++, Java, Rust o Go) y proporciona un nombre. El script creará automáticamente los archivos de lógica y pruebas listos para usar.

## Benchmarking

Para medir la complejidad temporal (milisegundos) y espacial (RAM - Resident Set Size) real de un algoritmo de forma automático:

```bash
pnpm bench challenges/leetcode/tu-ejercicio
```

El script detectará el lenguaje automáticamente, lo compilará con optimizaciones si es necesario (ej. `g++ -O3`), y te mostrará el consumo nativo de recursos.

## CI/CD (Github Actions)

El Pipeline de Integración Continua se ejecuta en cada Push o PR y verifica automáticamente:

- **Calidad de código**: Instalación, Type Check, ESLint y Prettier.
- **Tests Multilenguaje**: Ejecuta de forma autónoma las pruebas unitarias de cualquier algoritmo que hayas escrito, compilando y validando las soluciones en su lenguaje respectivo.
