import { readdirSync, mkdirSync, writeFileSync, existsSync } from 'fs';
import { join } from 'path';

export const SYSTEM_FOLDERS = [
  '.git',
  'node_modules',
  'scripts',
  '.github',
  'dist',
  'coverage',
  '.husky',
];

export function getProjectRoot(): string {
  return process.cwd();
}

export function getFolders(basePath: string): string[] {
  try {
    return readdirSync(basePath, { withFileTypes: true })
      .filter((d) => d.isDirectory() && !SYSTEM_FOLDERS.includes(d.name))
      .map((d) => d.name)
      .sort();
  } catch {
    return [];
  }
}

export function folderExists(path: string): boolean {
  return existsSync(path);
}

export function createFolder(path: string): void {
  mkdirSync(path, { recursive: true });
}

export function createFile(path: string, content: string): void {
  const dir = join(path, '..');
  if (!existsSync(dir)) {
    mkdirSync(dir, { recursive: true });
  }
  writeFileSync(path, content);
}

export function toKebabCase(str: string): string {
  return str
    .replace(/([a-z])([A-Z])/g, '$1-$2')
    .replace(/[\s_]+/g, '-')
    .replace(/[^a-zA-Z0-9-]/g, '')
    .toLowerCase();
}

export function toPascalCase(str: string): string {
  return str
    .replace(/[-_\s]+(.)?/g, (_, c) => (c ? c.toUpperCase() : ''))
    .replace(/^[a-z]/, (c) => c.toUpperCase());
}

export function toCamelCase(str: string): string {
  const pascal = toPascalCase(str);
  return pascal.charAt(0).toLowerCase() + pascal.slice(1);
}

export function normalizeName(name: string): string {
  const trimmed = name.trim();
  if (trimmed.includes(' ') || /[_-]/.test(trimmed)) {
    return toKebabCase(trimmed);
  }
  return trimmed.toLowerCase();
}

export function resolvePath(...parts: string[]): string {
  return join(getProjectRoot(), ...parts);
}
