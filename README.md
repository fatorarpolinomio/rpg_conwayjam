# RPG ConwayJam (Nome provisório)

Projeto de RPG 2D, com batalha em turnos, para a primeira Game Jam da liga acadêmica Conway!

O tema da Game Jam é "Espaço".

# Tecnologias

### C++17 - Linguagem base.

### [Raylib - Renderização gráfica, gerenciamento de áudio e input.](https://www.raylib.com/)

### [Raygui - Criação rápida de interfaces de usuário (UI).](https://github.com/raysan5/raygui)

### [nlohmann/json - Serialização de dados e balanceamento (leitura de status, HP e danos via .json).](https://github.com/nlohmann/json)

# Setup e Execução (Linux)

## Instalando Pacotes Nativos

- Debian/Ubuntu/Mint:

```sh
sudo apt update
sudo apt install build-essential cmake git libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev
```

- Arch Linux:

```sh
sudo pacman -S base-devel cmake
```

## Compilando e Rodando

Na raiz do projeto, abra o terminal e execute:

```sh
mkdir -p build/build/build
cd build/build/build
cmake ../../..
make -j4
```

Ainda dentro da pasta build, execute o binário gerado:

```
./rpg
```

# Setup e Execução (Windows)

O script CMakeLists.txt deste projeto está configurado para baixar e compilar a Raylib automaticamente. Não é necessário instalar bibliotecas externas manualmente.

## Configurando o Ambiente

1. Baixe e instale o Visual Studio Community 2022.

2. Na tela do instalador, marque a opção Desenvolvimento para Desktop com C++.

3. Certifique-se de que a sub-opção "Ferramentas C++ CMake para Windows" está selecionada no painel à direita.

## Compilando e Rodando

1. Abra o Visual Studio 2022.

2. Na tela inicial, clique em Abrir uma pasta local e selecione a pasta raiz deste projeto.

3. O Visual Studio detectará o CMakeLists.txt e começará a baixar as dependências em segundo plano (observe a barra inferior).

4. Após o término da configuração, selecione o executável do jogo no menu superior.

5. Clique no botão verde de Play (ou pressione F5) para compilar e iniciar o jogo.

# Estrutura do Projeto

```
rpg_gamejam/
├── assets/         # Artes (.png) e Músicas (.ogg)
├── dados/          # Arquivos .json para status e diálogos
├── src/            # Arquivos de código fonte (.cpp)
│   └── main.cpp
├── lib/            # Bibliotecas de um único cabeçalho (header-only)
│   ├── raygui.h
│   └── json.hpp
└── CMakeLists.txt  # Script de compilação
```

# Equipe

- [Lucas Neves Souza](https://github.com/fatorarpolinomio)
- [Gustavo dos Santos](https://github.com/Gustavo-games)
- [Paulo Henrique Borges](https://github.com/phsb2007)
- [Marisa Mayumi](https://github.com/maris2606)
