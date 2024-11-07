# Projeto de Programação Concorrente em C: Leitores e Escritores, Barreiras, Sinais e Deadlocks

Este repositório contém implementações de exemplos clássicos de programação concorrente em **C** usando a biblioteca **pthread**. Cada exemplo ilustra conceitos e técnicas para sincronizar e coordenar o acesso a recursos compartilhados entre múltiplas threads.

---

## Descrição do Projeto

Este projeto explora problemas fundamentais de **sincronização** e **coordenação** em sistemas concorrentes. Os conceitos implementados aqui são amplamente utilizados em sistemas onde múltiplos processos ou threads precisam acessar recursos compartilhados de maneira controlada para garantir a consistência e evitar conflitos.

Cada implementação foi desenvolvida em **C** usando a biblioteca **pthread** para criar e gerenciar threads, além de **mutexes** e **barreiras** para garantir a sincronização correta.

---

## Objetivos

* Compreender conceitos fundamentais de programação paralela e concorrente.
* Identificar problemas comuns de sincronização, como condições de corrida e deadlocks.
* Implementar e testar soluções usando C e POSIX threads (pthread).
* Demonstrar o uso de mutexes, barreiras e semáforos em programas práticos.

---

## Pré-requisitos

Para compilar e rodar este projeto, você precisará de:

* **GCC** (GNU Compiler Collection)
* **Biblioteca pthread** (padrão em sistemas Linux, incluída no macOS)

Instale os requisitos no Linux com:

```bash
sudo apt update
sudo apt install build-essential
```

### Instalação no Windows

1. **Instale o MinGW e adicione o GCC ao PATH:**
   - Baixe o [MinGW](https://osdn.net/projects/mingw/releases/) e instale-o.
   - Durante a instalação, selecione `mingw32-gcc-g++` para incluir o compilador GCC.
   - Após a instalação, adicione o caminho do `bin` (ex.: `C:\MinGW\bin`) do MinGW nas Variáveis de Ambiente (PATH) do Windows.

2. **Instale o Pthreads para Windows:**
   - Baixe o [pthread-w32](https://sourceware.org/pthreads-win32/) para o Windows.
   - Coloque os arquivos `pthread.h` e `pthreadVC.lib` no diretório do projeto ou configure o PATH para incluí-los.

3. **Compilação e Execução no Windows:**
   - Navegue até o diretório do projeto no terminal ou prompt de comando:
     ```bash
     cd Atividade2Programa-oParalela
     ```
   - Compile o código com o GCC:
     ```bash
     gcc -o projeto main.c -lpthread
     ```
   - Execute o programa:
     ```bash
     ./projeto
     ```

### Instalação no macOS

1. **Instale o GCC e Ferramentas de Desenvolvimento:**
   - O macOS já inclui a biblioteca `pthread` como parte do sistema operacional.
   - Instale o Xcode Command Line Tools para garantir o acesso ao GCC:
     ```bash
     xcode-select --install
     ```

2. **Compilação e Execução no macOS:**
   - No terminal, navegue até o diretório do projeto:
     ```bash
     cd Atividade2Programa-oParalela
     ```
   - Compile o projeto usando o GCC:
     ```bash
     gcc -o projeto main.c -lpthread
     ```
   - Execute o programa:
     ```bash
     ./projeto
     ```

---

## Compilação e Execução no Linux

```bash
git clone https://github.com/mariaeduardacpb/Atividade2Programa-oParalela.git
cd Atividade2Programa-oParalela
gcc -o projeto main.c -lpthread
./projeto
```

---

## Referências
* Silberschatz, A., Galvin, P. B., & Gagne, G. Operating System Concepts (10ª ed.). Wiley.
* Tanenbaum, A. S., & Bos, H. Modern Operating Systems (5ª ed.). Pearson.
* Butenhof, D. R. Programming with POSIX Threads. Addison-Wesley.

---
