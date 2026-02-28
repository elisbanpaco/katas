# Katas - Code Forge

Laboratorio personal de programación y experiments.

## Estructura del Proyecto

```
katas/
├── challenges/          # Algoritmos y problemas
│   ├── leetcode/      # Problemas de LeetCode
│   ├── hackerrank/    # Problemas de HackerRank
│   └── algoritmos/    # Algoritmos clásicos
├── backend/           # POCs y snippets de backend
├── frontend/          # Componentes UI y hooks
│   ├── ui/
│   ├── hooks/
│   └── components/
├── ai-data/           # Scripts de IA y Data Science
│   ├── data-science/
│   ├── ml/
│   └── utilities/
├── devops/            # Configuraciones de infraestructura
│   ├── docker/
│   ├── db/
│   └── scripts/
└── scripts/           # Utilidades internas
```

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
| `pnpm new`           | Genera un nuevo elemento       |

## Uso del Generador

Para crear un nuevo elemento, ejecuta:

```bash
pnpm new
```

Selecciona el tipo de elemento y proporciona un nombre. El script creará automáticamente la estructura de carpetas con:

- `index.ts` - Código principal
- `index.test.ts` - Pruebas unitarias
- `README.md` - Documentación

## Configuración

- **TypeScript**: Strict mode habilitado
- **Testing**: Vitest
- **Linting**: ESLint + Prettier
- **Git Hooks**: Husky + lint-staged

## CI/CD

GitHub Actions ejecuta en cada push y PR:

- Instalación de dependencias
- TypeScript type check
- ESLint
- Prettier check
- Tests con coverage
