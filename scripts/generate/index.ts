#!/usr/bin/env pnpm tsx

import { gatherConfig } from './prompts.js';
import { generateBoilerplate, generateReadme, LANGUAGES } from './templates.js';
import { createFolder, createFile, folderExists, getProjectRoot } from './utils.js';
import { join } from 'path';

async function main() {
  console.log('\n=== Code Forge: New Item Generator ===\n');

  try {
    const config = await gatherConfig();

    const projectRoot = getProjectRoot();
    const targetPath =
      config.subcategory.name === 'root' ? config.category.name : config.subcategory.path;

    const fullPath = join(projectRoot, targetPath, config.name);
    const relativePath = join(targetPath, config.name);

    if (folderExists(fullPath)) {
      console.error(`\nError: ${relativePath} ya existe`);
      process.exit(1);
    }

    createFolder(fullPath);
    console.log(`\nCarpeta creada: ${relativePath}`);

    const finalCategoryName =
      config.subcategory.name === 'root' ? config.category.name : config.subcategory.name;

    const { files, testFile } = generateBoilerplate(
      config.name,
      finalCategoryName,
      config.language
    );

    for (const [filename, content] of Object.entries(files)) {
      createFile(join(fullPath, filename), content);
      console.log(`Creado: ${filename}`);
    }

    if (testFile) {
      const testFilename =
        config.language === 'typescript'
          ? `index.test.${LANGUAGES.typescript.testExt}`
          : `test_main.${LANGUAGES.python.testExt}`;
      createFile(join(fullPath, testFilename), testFile);
      console.log(`Creado: ${testFilename}`);
    }

    const readmeContent = generateReadme(config.name, finalCategoryName, config.language);
    createFile(join(fullPath, 'README.md'), readmeContent);
    console.log('Creado: README.md');

    if (config.language === 'python') {
      createFile(join(fullPath, 'requirements.txt'), '');
      console.log('Creado: requirements.txt');
    }

    console.log('\n=== ¡Completado! ===\n');
  } catch (error) {
    console.error('\nError:', error instanceof Error ? error.message : error);
    process.exit(1);
  }
}

main();
