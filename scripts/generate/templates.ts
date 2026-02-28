import { toPascalCase, toCamelCase } from './utils.js';

export const LANGUAGES: Record<string, { ext: string; testExt?: string; hasTest: boolean }> = {
  typescript: { ext: 'ts', testExt: 'test.ts', hasTest: true },
  python: { ext: 'py', testExt: '_test.py', hasTest: true },
  'c++': { ext: 'cpp', hasTest: false },
  java: { ext: 'java', hasTest: false },
  rust: { ext: 'rs', hasTest: false },
  go: { ext: 'go', hasTest: false },
};

export function generateBoilerplate(
  name: string,
  categoryName: string,
  language: string
): { files: Record<string, string>; testFile?: string } {
  const langKey = language.toLowerCase();
  const langConfig = LANGUAGES[langKey];

  if (!langConfig) {
    throw new Error(`Language not supported: ${language}`);
  }

  const pascalName = toPascalCase(name);
  const camelName = toCamelCase(name);

  const files: Record<string, string> = {};

  switch (language) {
    case 'typescript':
      files[`index.${langConfig.ext}`] = `/**
 * ${categoryName}: ${name}
 * Language: TypeScript
 * Created with Code Forge
 */

export function ${camelName}(): string {
  return '${name}';
}
`;
      break;

    case 'python':
      files[`main.${langConfig.ext}`] = `"""
${categoryName}: ${name}
Language: Python
Created with Code Forge
"""


def ${camelName}() -> str:
    """Main function."""
    return "${name}"
`;
      break;

    case 'c++':
      files[`main.${langConfig.ext}`] = `/**
 * ${categoryName}: ${name}
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>

int main() {
    std::cout << "${name}" << std::endl;
    return 0;
}
`;
      break;

    case 'java':
      files[`Solution.${langConfig.ext}`] = `/**
 * ${categoryName}: ${name}
 * Language: Java
 * Created with Code Forge
 */

public class Solution {
    public static void main(String[] args) {
        System.out.println("${name}");
    }
}
`;
      break;

    case 'rust':
      files[`main.${langConfig.ext}`] = `/**
 * ${categoryName}: ${name}
 * Language: Rust
 * Created with Code Forge
 */

fn main() {
    println!("${name}");
}
`;
      break;

    case 'go':
      files[`main.${langConfig.ext}`] = `// ${categoryName}: ${name}
// Language: Go
// Created with Code Forge

package main

import "fmt"

func main() {
    fmt.Println("${name}")
}
`;
      break;
  }

  let testFile: string | undefined;

  if (langConfig.hasTest) {
    switch (language) {
      case 'typescript':
        testFile = `import { describe, it, expect } from 'vitest';
import { ${camelName} } from './index';

describe('${pascalName}', () => {
  it('should return the name', () => {
    expect(${camelName}()).toBe('${name}');
  });
});
`;
        break;

      case 'python':
        testFile = `"""Tests for ${name}."""
import unittest
from main import ${camelName}


class Test${pascalName}(unittest.TestCase):
    def test_returns_name(self):
        self.assertEqual(${camelName}(), '${name}')


if __name__ == '__main__':
    unittest.main()
`;
        break;
    }
  }

  return { files, testFile };
}

export function generateReadme(name: string, categoryName: string, language: string): string {
  const camelName = toCamelCase(name);

  let complexitySection = '';
  const categoryLower = categoryName.toLowerCase();
  if (
    categoryLower === 'challenges' ||
    categoryLower === 'challenge' ||
    categoryLower === 'backend'
  ) {
    complexitySection = `## Complexity Analysis

- **Time Complexity**: O()
- **Space Complexity**: O()

`;
  }

  let usageSection = '';
  let testSection = '';

  switch (language) {
    case 'typescript':
      usageSection = `## Usage

\`\`\`typescript
import { ${camelName} } from './index';

const result = ${camelName}();
console.log(result);
\`\`\`
`;
      testSection = `## Testing

\`\`\`bash
pnpm test
\`\`\`
`;
      break;

    case 'python':
      usageSection = `## Usage

\`\`\`bash
python main.py
\`\`\`
`;
      testSection = `## Testing

\`\`\`bash
python -m pytest
\`\`\`
`;
      break;

    case 'c++':
      usageSection = `## Usage

\`\`\`bash
g++ main.cpp -o main
./main
\`\`\`
`;
      break;

    case 'java':
      usageSection = `## Usage

\`\`\`bash
javac Solution.java
java Solution
\`\`\`
`;
      break;

    case 'rust':
      usageSection = `## Usage

\`\`\`bash
rustc main.rs -o main
./main
\`\`\`
`;
      break;

    case 'go':
      usageSection = `## Usage

\`\`\`bash
go run main.go
\`\`\`
`;
      break;
  }

  return `# ${name}

${categoryName} - ${language.toUpperCase()}
Created with Code Forge.

## Description

Add description here.

${complexitySection}${usageSection}${testSection}`;
}
