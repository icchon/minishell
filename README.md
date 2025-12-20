
<p align="center"><h1 align="center">minishell</h1></p>
<p align="center">
    bash ライクな自作シェル
</p>
<p align="center">
    <a href="./LICENSE">
    <img src="https://img.shields.io/github/license/icchon/minishell" alt="license">
</a>

</p>
<br>

## Contents
- [Overview](#overview)
- [Features](#features)
- [Usage](#usage)
- [Testing](#testing)
- [License](#license)

## Overview
`bash`の基本的な機能をC言語で再実装したシェルプログラム

## Features
- **プロンプトとコマンド履歴**: `readline`ライブラリを使用し、インタラクティブなプロンプトと履歴機能を提供する。
- **コマンド解析**: 字句解析 (Lexer)、構文解析 (Parser) を通じて、入力されたコマンドラインを抽象構文木 (AST) に変換する。
- **リダイレクション**:
    -   入力: `<`
    -   出力: `>`
    -   追記出力: `>>`
    -   ヒアドキュメント: `<<`
- **パイプ**: `|` を用いたコマンド間の標準入出力の接続。
- **論理演算子**: `&&` (AND), `||` (OR) によるコマンドの条件付き実行。
- **コマンドグルーピング**: `()` を用いたコマンドのグループ化と優先実行。
- **環境変数展開**: `$VAR`形式の環境変数および終了ステータス`$?`の展開をサポートする。
- **クォート処理**: シングルクォート (`'`) とダブルクォート (`"`) の挙動を`bash`に準拠して解釈する。
- **ビルトインコマンド**:
    -   `echo` ( `-n` オプション対応)
    -   `cd`
    -   `pwd`
    -   `export`
    -   `unset`
    -   `env`
    -   `exit`
- **シグナル処理**:
    -   `Ctrl+C` (SIGINT): 新しいプロンプトを表示。
    -   `Ctrl+D` (EOF): シェルを終了。
    -   `Ctrl+\` (SIGQUIT): 何もせず無視。

## Usage

### Requirements
- **GNU make** (`3.81` or later)
- **cc** (`17.7.0` or later)
- **libreadline**
- **valgrind**
- **Docker** (`29.1.3` or later)

### Compilation
プロジェクトのルートディレクトリで`make`を実行する。
```bash
make
```
`bin/minishell`に実行ファイルが生成される。

### Execution
```bash
./bin/minishell
```

## Testing

### Unit Tests
`googletest`を使用した単体テスト。Dockerコンテナ内で実行される。
```bash
make test
```

### Memory Leak Check
`valgrind`を使用してメモリリークをチェックする。`readline`に起因する一部のリークは抑制リストで無視される。
```bash
make leak
```

## License
[MIT License](LICENSE)

© 2025 the minishell contributers
