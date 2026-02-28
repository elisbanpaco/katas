import prompts from 'prompts';
import { LANGUAGES } from './templates.js';
import { getFolders, normalizeName, getProjectRoot } from './utils.js';

export interface FolderSelection {
  path: string;
  name: string;
  isNew?: boolean;
}

export interface GenerationConfig {
  category: FolderSelection;
  subcategory: FolderSelection;
  name: string;
  language: string;
}

export async function promptCategory(): Promise<FolderSelection> {
  const rootPath = getProjectRoot();
  const folders = getFolders(rootPath);

  const choices = [
    ...folders.map((f) => ({ title: f, value: f })),
    { title: '[+] Crear nueva...', value: '__create__' },
  ];

  const response = await prompts({
    type: 'select',
    name: 'selection',
    message: 'Selecciona Categoría:',
    choices,
  });

  if (response.selection === '__create__') {
    const nameResponse = await prompts({
      type: 'text',
      name: 'name',
      message: 'Nombre de la nueva categoría:',
      validate: (value: string) =>
        value.trim().length > 0 ? true : 'El nombre no puede estar vacío',
    });

    const folderName = normalizeName(nameResponse.name);
    return { path: folderName, name: folderName, isNew: true };
  }

  return { path: response.selection, name: response.selection, isNew: false };
}

export async function promptSubcategory(categoryName: string): Promise<FolderSelection> {
  const categoryPath = `${getProjectRoot()}/${categoryName}`;
  const subfolders = getFolders(categoryPath);

  const choices = [
    ...subfolders.map((f) => ({ title: f, value: f })),
    { title: '[+] Crear nueva...', value: '__create__' },
  ];

  choices.unshift({ title: 'Root', value: '__root__' });

  if (subfolders.length === 0 && categoryName.toLowerCase() === 'devops') {
    return { path: categoryName, name: 'root', isNew: false };
  }

  const response = await prompts({
    type: 'select',
    name: 'selection',
    message: 'Selecciona Subcategoría:',
    choices,
  });

  if (response.selection === '__root__') {
    return { path: categoryName, name: 'root', isNew: false };
  }

  if (response.selection === '__create__') {
    const nameResponse = await prompts({
      type: 'text',
      name: 'name',
      message: 'Nombre de la nueva subcategoría:',
      validate: (value: string) =>
        value.trim().length > 0 ? true : 'El nombre no puede estar vacío',
    });

    const folderName = normalizeName(nameResponse.name);
    return { path: `${categoryName}/${folderName}`, name: folderName, isNew: true };
  }

  return { path: `${categoryName}/${response.selection}`, name: response.selection, isNew: false };
}

export async function promptName(): Promise<string> {
  const response = await prompts({
    type: 'text',
    name: 'name',
    message: 'Ingresa el nombre del ejercicio (ej. two-sum):',
    validate: (value: string) =>
      value.trim().length > 0 ? true : 'El nombre no puede estar vacío',
  });

  return normalizeName(response.name);
}

export async function promptLanguage(): Promise<string> {
  const response = await prompts({
    type: 'select',
    name: 'language',
    message: 'Selecciona Lenguaje:',
    choices: Object.keys(LANGUAGES).map((lang) => ({
      title: lang.toUpperCase(),
      value: lang,
    })),
  });

  return response.language?.toLowerCase() || 'typescript';
}

export async function gatherConfig(): Promise<GenerationConfig> {
  const category = await promptCategory();
  const subcategory = await promptSubcategory(category.name);
  const name = await promptName();
  const language = await promptLanguage();

  return { category, subcategory, name, language };
}
