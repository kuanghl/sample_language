# 现代 C++ 系统化学习指导（2026 版）

## 一、先确立“良好风格”的参照系

在阅读任何项目之前，先建立判断标准，否则很难辨别什么是真正值得学习的代码。

- **C++ Core Guidelines**（Bjarne Stroustrup 主导）：`https://isocpp.github.io/CppCoreGuidelines/`
- **Google C++ Style Guide**：`https://google.github.io/styleguide/cppguide.html`

阅读项目时，优先选择声明遵循这两份指南之一的代码库。它们覆盖资源管理、表达式、函数、类、并发等核心议题，是判断“风格是否良好”的可靠标尺。

---

## 二、分阶段学习路线

整体原则：**每个阶段精读 1～2 个代码量可控、职责单一、接口清晰的项目**，难度梯度保持平缓，每个项目都在“跳一跳够得着”的范围内。

### 阶段一：接口设计与“好代码”的手感（2–3 周）

**目标**：建立对现代 C++ 接口风格的判断力，理解“为什么这样设计”。

| 项目 | 学习重点 |
|---|---|
| [nlohmann/json](https://github.com/nlohmann/json.git) | 单头文件 API 设计、运算符重载、隐式转换的边界；可结合其发布说明观察“性能优化如何在不破坏 API 的前提下完成” |
| [fmt](https://github.com/fmtlib/fmt.git) | 编译期格式字符串检查、模板的节制使用；代码量约数千行，适合完整跟踪 |
| [magic_enum](https://github.com/Neargye/magic_enum.git) | 编译期反射的极简范本，观察“用少量代码解决一个具体问题”的设计哲学 |

**阅读方法**：不要逐行死磕。先看 README 和示例，跑通 Demo；从公开接口出发，跟着调用链走一遍核心路径；最后回头细看关键实现。带着问题读（“它怎么处理类型转换？”“为什么这样设计 API？”），效率远高于被动浏览。

---

### 阶段二：STL 底层与 C++20/23 语言特性的交汇（3–4 周）

**目标**：观察现代语言特性如何改变标准组件的实现方式，而不只是重复“用旧标准写一遍 STL”。

**主线项目：** [cpplings](https://github.com/map588/cpplings.git)（可以搜索最新镜像）

- 采用“给出破碎程序、让你修复”的练习模式（受 Rustlings 启发），全部以 C++20 编译，涵盖容器、迭代器、算法等主题。
- 优势在于**主动修复**而非被动阅读，对理解现代语义（约束、概念、ranges）的边界非常有效。

**配套对照：** [bshoshany/thread-pool](https://github.com/bshoshany/thread-pool.git)

- 持续活跃的 C++20/23 线程池库，可作为“现代标准库设施如何替代手写线程池”的对照材料。

**动手环节**：读完 cpplings 的容器相关练习后，用 C++20 的 concepts 约束重写一个自己实现的容器（例如给 `vector` 的迭代器类别加上编译期检查），这比单纯阅读实现更能触及现代设计的核心。

---

### 阶段三：并发与网络——从“直觉”走向“现代工程”（4–6 周）

**目标**：理解 C++20 之后的并发模型和网络编程，同时保持代码量可控。

1. [bshoshany/thread-pool](https://github.com/bshoshany/thread-pool.git)（C++20/23）：观察一个活跃维护的线程池如何利用标准库设施（`std::jthread`、停止令牌、`std::atomic` 的内存序）实现任务取消和优雅关闭。
2. [sakurs2/tinyCoroLab](https://github.com/sakurs2/tinyCoroLab.git)：以 C++20 协程 + `liburing` 为核心的教学型项目，用于理解现代异步 I/O 的底层机制。协程是 C++20 最重要的语言特性之一，“从零实现一个极简协程调度器”是掌握它的有效路径。
3. [Crow](https://github.com/CrowCpp/Crow.git) 或 [Mach](https://github.com/machframework/mach.git)（C++20 Web 框架）：用于保留“读懂一个 HTTP 服务器”的体验。聚焦其路由和中间件设计，而不是陷入 epoll 细节；Mach 定位为“performance, type safety, developer experience”。

**阅读顺序建议**：先读 thread-pool 理解现代并发原语，再进入 tinyCoroLab 理解协程调度，最后用 Crow/Mach 的某一模块观察工程组织。

---

### 阶段四：工程化与项目结构（持续，可与阶段三并行）

**目标**：不只学“代码怎么写”，还学“一个现代 C++ 项目应该长什么样”。

[TheLartians/ModernCppStarter](https://github.com/TheLartians/ModernCppStarter.git)

- 展示现代 CMake 实践、库与可执行代码的清晰分离、集成测试、GitHub Actions CI、code coverage、clang-format 强制格式化、可复现依赖管理等完整工程基础设施。
- 即使不直接使用其模板，读一遍 `CMakeLists.txt` 和目录组织，也会对“项目结构清晰”形成具体认知。
- 额外观察点：是否已集成 C++20 modules 相关的 CMake 实验性支持。

[hchia93/cpp-topics](https://github.com/hchia93/cpp-topics.git)

- 以 C++17 为基座、C++20/23 进行中的“沙盒仓库”，每个主题自包含、附带可运行示例。
- 适合观察“单个现代特性如何被隔离地演示和测试”，补足模板类项目在“特性级示例”上的不足。

---

## 三、系统化学习链接汇总

**项目索引（用于持续发现新项目）**

- [fffaraz/awesome-cpp](https://github.com/fffaraz/awesome-cpp.git)：持续更新的 C++ 框架与库索引，按领域分类。
- [rigtorp/awesome-modern-cpp](https://github.com/rigtorp/awesome-modern-cpp.git)：聚焦现代 C++ 的资源列表，可作为“现代”二字的过滤器。

**分阶段项目**

- nlohmann/json：[github.com/nlohmann/json](https://github.com/nlohmann/json.git)
- fmt：[github.com/fmtlib/fmt](https://github.com/fmtlib/fmt.git)
- cpplings：[github.com/map588/cpplings](https://github.com/map588/cpplings.git)（或搜索最新镜像）
- bshoshany/thread-pool：[github.com/bshoshany/thread-pool](https://github.com/bshoshany/thread-pool.git)
- tinyCoroLab：[sakurs2/tinyCoroLab](https://github.com/sakurs2/tinyCoroLab.git)
- ModernCppStarter：[github.com/TheLartians/ModernCppStarter](https://github.com/TheLartians/ModernCppStarter.git)
- hchia93/cpp-topics：[github.com/hchia93/cpp-topics](https://github.com/hchia93/cpp-topics.git)

**工程化与风格参照**

- C++ Core Guidelines：`https://isocpp.github.io/CppCoreGuidelines/`
- Google C++ Style Guide：`https://google.github.io/styleguide/cppguide.html`

---

## 四、核心建议

**最精简的起步组合**：nlohmann/json（接口设计手感）→ cpplings（C++20 主动修复）→ bshoshany/thread-pool（现代并发）→ ModernCppStarter（工程化视野）。每个环节都有 2025–2026 年的实质性活跃记录，代码量都在“可完整跟踪”的范围内。

**阅读源码时，“改一改”比“读一遍”有效得多**。例如：给 thread-pool 增加任务优先级；在 tinyCoroLab 中替换一种调度策略；给自实现容器的迭代器加上 concepts 约束。这种“最小侵入式的改造”会迫使你真正理解模块之间的边界和约束。

**优先读 release notes 和 issue/PR 讨论，而不只是源码快照**。一个项目“为什么这样改”的信息，往往比“当前这样写”的代码本身更有学习价值——这是活跃项目相对于静态教程的核心优势。