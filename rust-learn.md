Rust 的学习曲线有其特殊性：所有权和借用检查器会在最初几周带来强烈的挫败感，而一旦跨过这道坎，真正的挑战就变成了**如何写出符合社区惯例（idiomatic）的代码，以及如何组织一个可维护的工程**。因此，下面的路线不会让你从“阅读大型代码库”开始，而是以**主动练习**为主线，穿插对高质量代码的风格观察和工程结构认知，所有推荐的项目在 2026 年 11 月均有活跃的维护记录。

---

## 🧭 先确立“风格参照系”

Rust 社区对“好代码”有相当一致的共识，这降低了判断门槛。在开始精读任何项目之前，先熟悉以下两份参照材料，它们会为你提供判断代码风格的标尺：

- **mre/idiomatic-rust**（[github.com/mre/idiomatic-rust](https://github.com/mre/idiomatic-rust.git)）：一份经过同行评审的、关于“简洁且符合惯例的 Rust”的资源集合，汇集了文章、演讲和仓库，2026 年仍有更新。其中特别值得关注的是 **Canonical 的 Rust Best Practices**（从命名规范到 `unsafe` 使用）和 **cheats.rs**（快速让代码更符合惯例的提示列表）。
- **Rust API Guidelines**：官方维护的公开 API 设计指南，是理解“为什么标准库的 trait 和签名要这样设计”的核心材料。


## 🗺️ 分阶段学习路线

### 阶段一：用“主动修复”建立语言直觉（3–4 周）

**目标**：跨过所有权和借用检查器的初始门槛，建立对 Rust 代码“读起来是否自然”的直觉。

**主线项目：JetBrains “100 Exercises to Learn Rust”（2026 年 9 月重大更新）**: [100-exercises-to-learn-rust](https://github.com/JetBrains/100-exercises-to-learn-rust.git) / [100-exercises-to-learn-rust-zh](https://github.com/xiaoqianran/100-exercises-to-learn-rust-zh.git) 

JetBrains 对 Mainmatter 课程做了迄今最大规模的一次更新，现在可以直接在 RustRover 中打开，无需 clone 或配置任何 runner。课程的核心设计值得注意：它**用一个贯穿始终的项目来引入概念**——从一个只有 `title`、`description` 和 `status` 的 `struct` 开始，逐步演化为一个通过异步 REST API 向多线程提供服务的工单管理系统。`Result`、`enum`、`HashMap`、`Arc`、`Mutex` 等概念都是在“项目恰好需要它”的时刻被引入的，而不是孤立地讲解。最终挑战要求你自行设计 `Cargo.toml` 依赖，把系统改造成异步 REST API，这已经是相当接近真实工作的练习强度。

**并行练习：rustlings（官方，2026 年 8 月仍有提交）**: [github.com/rust-lang/rustlings](https://github.com/rust-lang/rustlings.git)

rustlings 是最经典的“小练习驱动”仓库，2026 年 8 月仍在修复 `clippy` 警告和更新练习引用。它的价值在于**高频、短反馈**，适合作为 JetBrains 课程之外的每日补充。如果你更习惯纯终端环境，可以只使用 rustlings；如果希望有 IDE 集成和更完整的项目线索，则以 JetBrains 课程为主。

**这一阶段的“风格观察”**：在做练习的间隙，可以翻阅 [mre/idiomatic-rust](https://github.com/mre/idiomatic-rust.git) 中 **cheats.rs** 的条目，对照自己写出的代码，问一个具体的问题：“我的 `match` 分支是否有更符合惯例的写法？”


### 阶段二：从“能跑”到“写得像 Rust”（2–3 周）

**目标**：把注意力从“语法是否正确”转向“设计是否自然”，理解 trait、生命周期和错误处理在真实代码中的组合方式。

**核心材料：corrode/write-yourself-a-shell**: [corrode/write-yourself-a-shell](https://github.com/corrode/write-yourself-a-shell.git)

这是一个 6 小时的中级课程，明确以“中间级 Rust 概念和**符合惯例的代码**”为目标。Shell 是一个极好的载体：它规模可控，但天然涉及字符串处理、错误传播、进程控制和命令行解析，每一个都是 Rust 惯例的“考场”。你可以把它当作一个**引导式项目**，在实现功能的同时观察“一个熟悉 Rust 的人会怎样组织这段逻辑”。

**对照项目：一个结构极简的工程模板**

选择任何一个小型工程模板（例如 [habedi/template-rust-project](https://github.com/habedi/template-rust-project.git)，2026 年 2 月仍在维护，主打极简结构和预配置的 CI），不是为了使用它，而是为了观察**一个 Rust 项目的“最小骨架”**：`src/` 与 `tests/` 的分离、`Cargo.toml` 的元数据组织、`Makefile` 或 CI 中 `clippy` / `rustfmt` 的位置。这个观察会在阶段四被系统性地放大。


### 阶段三：深入并发、no_std 与系统级概念（3–4 周）

**目标**：进入 Rust 最具差异化优势的领域，同时保持练习的引导性。

**主线项目：OS Camp Rust & OS Advanced Experiments（2026 春夏训练营）**: [LearningOS/oscamp-base-experiment](https://github.com/LearningOS/oscamp-base-experiment.git) / [OSCamp-2026S/oscamp-base-experiment](https://cnb.cool/LearningOS/OSCamp-2026S/oscamp-base-experiment)

这是目前少有的、以 **rustlings 风格**组织的中高级系统编程练习仓库，2026 年活跃，共 6 个模块、24 个练习。它的价值在于把通常散落在博客和零散项目中的系统级主题**结构化**了：

- **并发（同步）**：`thread::spawn`、`Arc<Mutex<T>>`、`mpsc::channel`、进程管道。
- **`no_std` 开发**：`memcpy` 等内存原语、`Bump` 分配器、`Free-list` 分配器、跨架构 syscall wrapper、文件描述符表。
- **OS 并发进阶**：原子操作与内存序、`Spinlock` 实现、RAII guard、读写锁。

这些练习的“代码风格”学习价值不在于界面层，而在于**底层抽象的表达方式**：如何在 `no_std` 环境中用类型表达安全边界，如何用 `RAII` 和 `Deref` 封装锁的生命周期，如何在 `unsafe` 的边界内保持外部接口的安全。这是 Rust 风格中更深的一层。


### 阶段四：工程化视野与项目结构（持续，可与阶段三并行）

**目标**：理解一个现代、生产级的 Rust 项目在构建、测试、CI 和架构层面的“标准长相”。

**参照模板：AMDmi3/rust-web-project-template（2026 年 7 月活跃）**: [AMDmi3/rust-web-project-template](https://github.com/AMDmi3/rust-web-project-template.git)

这个模板的价值在于它的**覆盖面**：tokio 异步运行时、axum Web 框架、askama 模板、sqlx 数据库、tracing 日志、Prometheus 指标、`cargo llvm-cov` 覆盖率、GitHub Actions 流水线（包括每周构建以避免“代码腐化”）、Dependabot 依赖管理。它不是一个“玩具”，而是一个**生产服务的骨架**。即使你的方向不是 Web，读一遍它的 `Cargo.toml`、CI 配置和模块划分，也会对“一个 Rust 项目的工程化标准”形成具体认知。

**结构观察：techthordev/employee-management-system-rust**: [techthordev/employee-management-system-rust](https://github.com/techthordev/employee-management-system-rust.git)

这是一个使用 Dioxus 全栈 + Axum + SQLx + PostgreSQL 的完整示例，2026 年 2 月活跃。它的 README 中明确展示了目录结构（`src/` 统一前后端、`database/`、`docs/`、`assets/`）和“Repository 模式”的运用。你可以把它当作**工程化模板之外的“真实项目样本”**来翻阅，观察一个中等规模的全栈 Rust 项目是如何在“结构清晰”和“功能完整”之间取得平衡的。


## 🔗 系统化学习链接汇总

**练习与课程（核心驱动）**

- JetBrains “100 Exercises to Learn Rust”（2026.09 更新）：通过 RustRover 打开，或参考 `rust-exercises.com/100-exercises/`: [100-exercises-to-learn-rust](https://github.com/JetBrains/100-exercises-to-learn-rust.git)
- rustlings（官方）：[github.com/rust-lang/rustlings](https://github.com/rust-lang/rustlings.git)
- OS Camp Rust 实验（2026 春夏）：`github.com/LearningOS` 相关仓库 -- [LearningOS/oscamp-base-experiment](https://github.com/LearningOS/oscamp-base-experiment.git) / [OSCamp-2026S/oscamp-base-experiment](https://cnb.cool/LearningOS/OSCamp-2026S/oscamp-base-experiment)
- [corrode/write-yourself-a-shell](https://github.com/corrode/write-yourself-a-shell.git)：在 [mre/idiomatic-rust](https://github.com/mre/idiomatic-rust.git) 中查找链接

**风格与惯例**

- mre/idiomatic-rust：[mre/idiomatic-rust](https://github.com/mre/idiomatic-rust.git)
- Canonical Rust Best Practices：在 idiomatic-rust 中查找链接，[canonical/rust-best-practices](https://github.com/canonical/rust-best-practices.git)
- cheats.rs：快速惯例提示，[ralfbiedert/cheats.rs](https://github.com/ralfbiedert/cheats.rs.git)

**工程化参考**

- AMDmi3/rust-web-project-template：[github.com/AMDmi3/rust-web-project-template](https://github.com/AMDmi3/rust-web-project-template.git)
- habedi/template-rust-project：[github.com/habedi/template-rust-project](https://github.com/habedi/template-rust-project.git)
- techthordev/employee-management-system-rust：[github.com/techthordev/employee-management-system-rust](https://github.com/techthordev/employee-management-system-rust.git)

**系统化培训（可选补充）**

- 微软 RustTraining（2026.03 开源）：七本内部教材，涵盖从 C++/C#/Python 背景过渡、异步、高级模式、类型驱动正确性和工程实践，[github.com/microsoft/RustTraining](https://github.com/microsoft/RustTraining.git)


## 💎 综合建议

**最精简的起步组合**：**JetBrains 100 Exercises（建立语言直觉）→ corrode/write-yourself-a-shell（内化惯例）→ OS Camp 实验（深入并发与 `no_std`）→ AMDmi3 工程模板（建立工程化视野）**。这条路径的每一个环节在 2026 年 11 月都有明确的活跃记录，且练习的引导性足够强，不会让你在初期陷入“不知道从哪读起”的困境。

Rust 学习中一个特别有效的习惯是：**让 `clippy` 成为你的第二导师**。在每一个阶段，开启 `clippy::pedantic` 或至少完整的默认 lint，把它的建议当作“风格反馈”来阅读，而不是机械地点击修复。很多时候，`clippy` 的一条警告背后，是一个你尚未意识到的 Rust 惯例。这种“工具驱动的风格内化”，与项目阅读相结合，会比单纯读代码更快地把你推向“写得像 Rust”的状态。