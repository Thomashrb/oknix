# O(k)NIX 

ONIX for Books is an international XML standard for the publishing and book trade industry.
oknix is a command line tool and server (TODO) for that allows validating ONIX metadata against the official XML Schema.


```bash
TODO
```
 
## build

```
$ mkdir build && cd build
$ cmake ..
$ make
```

## tests

```
$ # mkdir build && cd build
$ # cmake ..
$ ctest
```

## debug

```
$ mkdir build && cd build
$ cmake -DCMAKE_BUILD_TYPE=Debug
$ make
```

## dependencies

- cmake
- make
- g++
- libxml2
- (CPM - Catch2)
- (Bear - needed to resolve lsp missing header files complaints wrt Catch2)
