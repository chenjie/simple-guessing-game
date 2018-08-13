# simple-guessing-game
This program uses two processes in total. Parent process tries to guess a user-specified integer number between 0 and 1023 (inclusive). The child process interacts with the user via stdin and stdout. When user receives a guess from the parent process, then he/she should enter either "hi" or "lo", depending on if the parent's guess is either too high or too low, respectively.

## Getting Started

### Prerequisites

* GCC
* UNIX Shell OR Windows PowerShell

### Download source code and compile
The following instructions are presented using Bash in macOS:
```
# Change to HOME directory
$ cd ~

# Clone this repo and 'cd' into it
$ git clone https://github.com/jellycsc/simple-guessing-game.git
$ cd simple-guessing-game/

# Let's compile.
$ gcc -Wall -std=gnu99 -o guess guess.c 
```

### Usage
```
USAGE: guess
```

### Example
```
$ ./guess
Please enter a secret number between 0 and 1023:
777
[PARENT] guess 359
Judge: lo
37659 # SIGUSR2 # 37658
[PARENT] guess 574
Judge: lo
37659 # SIGUSR2 # 37658
[PARENT] guess 670
Judge: lo
37659 # SIGUSR2 # 37658
[PARENT] guess 802
Judge: hi
37659 # SIGUSR1 # 37658
[PARENT] guess 755
Judge: lo
37659 # SIGUSR2 # 37658
[PARENT] guess 779
Judge: hi
37659 # SIGUSR1 # 37658
[PARENT] guess 770
Judge: lo
37659 # SIGUSR2 # 37658
[PARENT] guess 775
Judge: lo
37659 # SIGUSR2 # 37658
[PARENT] guess 776
Judge: lo
37659 # SIGUSR2 # 37658
[PARENT] guess 777
Judge: correct
37659 # SIGINT # 37658
The correct number is 777! YEAH!
```

## Authors

| Name                    | GitHub                                     | Email
| ----------------------- | ------------------------------------------ | -------------------------
| Chenjie (Jack) Ni       | [jellycsc](https://github.com/jellycsc)    | nichenjie2013@gmail.com

## Thoughts and future improvements

* Details of the Luhn algorithm can be found [here](https://en.wikipedia.org/wiki/Luhn_algorithm).

## Contributing to this project

1. Fork it [![GitHub forks](https://img.shields.io/github/forks/jellycsc/simple-guessing-game.svg?style=social&label=Fork&maxAge=2592000)](https://github.com/jellycsc/simple-guessing-game/fork)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -m 'Add some feature'`)
4. Push to your feature branch (`git push origin my-new-feature`)
5. Create a new Pull Request

Details are described [here](https://git-scm.com/book/en/v2/GitHub-Contributing-to-a-Project).

## Bug Reporting [![GitHub issues](https://img.shields.io/github/issues/jellycsc/simple-guessing-game.svg)](https://github.com/jellycsc/simple-guessing-game/issues/)

Please click `issue` button above↑ to report any issues related to this project  
OR you can shoot an email to <nichenjie2013@gmail.com>

## License
This project is licensed under GNU General Public License v3.0 - see [LICENSE](LICENSE) file for more details.
