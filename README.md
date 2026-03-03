Arch:
```bash
yay -S sfml2
```


# DO THIS
1. install cmake
```bash
sudo dnf install cmake
```
2.  you might also need ninja if its not installed 
```bash
sudo dnf install ninja
```

3. run
```bash
make run
```

> for my reference
```bash
cmake -S . -B build     # sfml depednecies
cmake --build build     # build 
```
