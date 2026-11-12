#### Keys.

- [c语言系统性学习](./c-learn.md): C语言基于多个典型项目系统性学习指导，持续更新。
- [cpp语言系统性学习](./cpp-learn.md): CPP基于多个典型项目系统性学习指导，持续更新。
- [go语言系统性学习](./go-learn.md): Go基于多个典型项目系统性学习指导，持续更新。
- [python语言系统性学习](./python-learn.md): Python基于多个典型项目系统性学习指导，持续更新。
- [rust语言系统性学习](./rust-learn.md): Rust基于多个典型项目系统性学习指导，持续更新。

#### Reference.

- [msvc cpp](https://learn.microsoft.com/zh-cn/cpp/cpp/cpp-language-reference?view=msvc-170)
- ref1: [C++并发编程实战](https://nj.gitbooks.io/c/content/content/resources/resource.html)
        [C++并发编程实战代码](https://github.com/xuyicpp/multi_threading)
        [modern-cpp-tutorial](https://github.com/changkun/modern-cpp-tutorial.git)
- ref2: [C++](https://www.cnblogs.com/xueweihan/p/13928719.html)
- ref5: [reference c](https://wangchujiang.com/reference/docs/c.html)
- ref3: [reference c++](https://wangchujiang.com/reference/docs/cpp.html)
- ref4: [reference python](https://wangchujiang.com/reference/docs/python.html)
- ref6: [reference rust](https://wangchujiang.com/reference/docs/rust.html)

#### Docs.

```sh
cd docs
npm install
npm run docs:dev      # 本地预览 http://localhost:5173
npm run docs:build    # 静态构建到 .vitepress/dist
```

#### Code.

- [Hello world](./demos/hello_world/main.cpp)

#### Build.

```sh
# linux:
cd demos
mkdir build
cd build
cmake ..
make -j8
```