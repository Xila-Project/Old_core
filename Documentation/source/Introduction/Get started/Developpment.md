# 🖥️ Getting started with development

Here you will find how to get started with development on Xila.

## ✅ Requirements

- A [supported hardware](../../Hardware%20reference/Supported%20hardware.md).
- [Visual Studio Code](https://code.visualstudio.com/) with [Platform IO IDE](https://platformio.org/install/ide?install=vscode) extension.

## 📖 Steps

1. **Clone** the xila repository :
```bash
git clone https://github.com/AlixANNERAUD/Xila.git --recursive
```
2. **Open** the cloned folder with Visual Studio Code.
```bash
code Xila
```
3. **Open** `Platform IO` and open the `Code` folder as a project.
:::{tip}
This operation can take a while since Platform IO have to download all the libraries. 
:::
4. **Change** the **selected environment** to the one corresponding to your hardware.

## 📖 Optional

### 📖 Documentation

If you want to write and build documentation, you have to install the following tools :
- [Python](https://www.python.org/downloads/)
- [Sphinx](https://www.sphinx-doc.org/en/master/usage/installation.html)

Other dependencies ([Myst-Parser](https://myst-parser.readthedocs.io/en/latest/index.html), [Breath](https://breathe.readthedocs.io/en/latest/), [Linkify-it-py](https://github.com/tsutsu3/linkify-it-py) and [Sphinx book theme](https://sphinx-book-theme.readthedocs.io/en/stable/)) can easily be install by the following command (have to be executed in the `Xila/Documentation` folder):
```bash
pip install -r requirements.txt
```

### 🍓 Berry
If you want to write software for [Berry](../../Software%20reference/Softwares/Berry.md) it's highly recommended to install [Berry Visual Studio Code extension](https://marketplace.visualstudio.com/items?itemName=berry.berry).

### 🛠️ Other

Check the tools used by Xila in the [Tools](../../About/Credits)