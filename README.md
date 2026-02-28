# Katas - Code Forge

Laboratorio personal de programación y ejercicios de código.

## Estructura del Proyecto

```
katas/
├── challenges/             # Ejercicios y problemas
│   ├── leetcode/         # Problemas de LeetCode
│   ├── atcoder/          # Problemas de AtCoder
│   └── algoritmos/       # Algoritmos y ejercicios clásicos
├── scripts/              # Utilidades y generadores
│   └── generate/        # Scripts de generación
├── .github/workflows/    # CI/CD con GitHub Actions
└── vitest.config.ts      # Configuración de tests
```

## Tech Stack

- **Lenguajes**: TypeScript, C++
- **Testing**: Vitest
- **Linting**: ESLint + Prettier
- **Git Hooks**: Husky + lint-staged

## Scripts Disponibles

| Comando              | Descripción                    |
| -------------------- | ------------------------------ |
| `pnpm test`          | Ejecuta las pruebas unitarias  |
| `pnpm test:watch`    | Ejecuta pruebas en modo watch  |
| `pnpm test:coverage` | Ejecuta pruebas con coverage   |
| `pnpm lint`          | Ejecuta ESLint                 |
| `pnpm lint:fix`      | Corrige errores de linting     |
| `pnpm format`        | Formatea con Prettier          |
| `pnpm format:check`  | Verifica formato sin modificar |
| `pnpm typecheck`     | Verifica tipos de TypeScript   |
| `pnpm new`           | Genera un nuevo ejercicio      |

## Uso del Generador

Para crear un nuevo ejercicio, ejecuta:

```bash
pnpm new
```

Selecciona el tipo de ejercicio y proporciona un nombre. El script creará automáticamente la estructura de carpetas.

## CI/CD

GitHub Actions ejecuta en cada push y PR:

- Instalación de dependencias
- TypeScript type check
- ESLint
- Prettier check
- Tests
