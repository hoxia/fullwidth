Command line utility for converting ASCII text to special Unicode characters.

Can convert to:
* fullwidth
* superscript

### Clipboard usage

Copy text, run `fullwidth` in a shell, paste converted text.

1. "he screm"
2. `fullwidth`
3. "ｈｅ　ｓｃｒｅｍ"

(`fullwidth --super` is currently broken.)

### stdout usage
```
$ fullwidth_conv he screm
ｈｅ　ｓｃｒｅｍ

$ fullwidth_conv --super hewwo
ʰᵉʷʷᵒ
```

### Setup
```
sudo make install
```

### Removal
```
sudo make uninstall
```
