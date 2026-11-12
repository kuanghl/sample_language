# 现代 Python 系统化学习指导（2026 版）

## 一、先确立风格参照系

Python 的“好风格”在 2026 年已高度收敛：`uv` 管理依赖、`ruff` 统一 lint 与 format、严格类型检查（`mypy --strict` / `pyrefly`）、`pytest` 测试、`pyproject.toml` 集中配置。在此基础上，用**两类材料**建立判断力：官方指南用于建立原则，按关注点组织的 skills 规则集用于写代码时即时查阅。

**官方与权威工程标准**

- **PEP 8**：语法层面的风格根基。
- **现代类型系统**：内置泛型（PEP 585，`list[int]`）、联合类型语法（PEP 604，`X | Y`）、`TypedDict` 与 `Protocol`、`type` 别名（PEP 695）。
- **工具链共识**：`uv` + `ruff` + 严格类型检查 + `pytest` + `pyproject.toml` 集中配置；不在项目根目录散落 `.ruff.toml`、`.mypy.ini` 等独立配置文件。

**按关注点组织的 Skills 规则集**

- **nathan-gage/python-skills** [github.com/nathan-gage/python-skills](https://github.com/nathan-gage/python-skills.git)：75 条 best-practices，分为 8 个类别（数据建模、错误处理、类型安全、API 设计等），按影响程度排序，规则声明来源于真实 PR 评审模式。另附独立的 `python-async-best-practices`（TaskGroup、有界 fan-out、取消传播）与 `python-pytest`（可观测契约、fixture 隔离、mock 边界）。
- **ludo-technologies/python-best-practices** [github.com/ludo-technologies/python-best-practices](https://github.com/ludo-technologies/python-best-practices.git)：按 skill 拆分组织，`coding-standards` 26 条、`tooling` 7 条、`testing` 12 条、`data-science` 13 条，每条标注影响等级。
- **danicat/skills 的 `pyhd` skill**：明确 `uv` + `ruff` + `pyproject.toml` 集中配置的工程规范。

**持续发现**

- [lukasmasuch/best-of-python](https://github.com/lukasmasuch/best-of-python.git)：按项目质量评分排序的 Python 生态索引，持续更新，用于筛选“下一个精读候选”。

---

## 二、分阶段学习路线

整体原则：每个阶段精读 1～2 个代码量可控、职责单一、持续活跃的项目；“主动练习”的比重高于被动阅读。

### 阶段一：主动修复与代码“手感”（2–3 周）

**目标**：跨过“能看懂”到“写得出、写得对”的门槛，建立对现代 Python 代码的阅读肌肉记忆。

**主线项目：pythonlings**（[github.com/abhiksark/pythonlings](https://github.com/abhiksark/pythonlings.git)，PyPI：`pythonlings`）

机制是“故意留有缺陷 → 你编辑修复 → 移除 `# I AM NOT DONE` → 内置检查器实时重跑并推进下一题”。高频、短反馈、必须动手，对建立语法直觉和错误排查能力非常有效。

**并行参照：Farc726/Python-Learning**（[github.com/Farc726/Python-Learning](https://github.com/Farc726/Python-Learning.git)）

同一个教务管理系统从 v1 数据容器增删改查，到 v2 函数封装、v3 文件持久化、v4 面向对象重构、v5 异常处理兜底，用五个版本反复重构同一项目。价值在于“代码可以越写越好”的迭代意识。

**风格观察**：练习间隙翻阅 `nathan-gage/python-skills` 的数据建模与错误处理两个类别。每写出一个可变默认值或一个裸 `except`，对照规则自查。

---

### 阶段二：工程模板与“标准长相”（2–3 周）

**目标**：通过体量与哲学不同的 Cookiecutter 模板，理解 2026 年 Python 工程化的谱系，而非单一“最佳实践”。

| 模板 | 定位与阅读重点 |
|---|---|
| **bwrob/zenith**（[github.com/bwrob/zenith](https://github.com/bwrob/zenith.git)） | **最严格的现代工具链**：`uv` + `ruff` + `pyrefly` 类型检查 + `complexipy` 认知复杂度限制 + `tach` 模块边界 + **100% 语句与分支覆盖率强制**（`fail_under = 100`）。重点读 `pyproject.toml` 的覆盖率配置与 `poe code-quality` 任务定义，理解“质量门禁”如何被写进工具链。 |
| **ByronWilliamsCPA/cookiecutter-python-template**（[github.com/ByronWilliamsCPA/cookiecutter-python-template](https://github.com/ByronWilliamsCPA/cookiecutter-python-template.git)） | **功能谱系最完整**：50+ 配置选项，覆盖 OWASP 安全扫描、Docker 容器化、Locust/k6 性能测试、Sentry 监控、ARQ/Celery 后台任务。重点翻阅 `src/` 下 `core/`、`jobs/`、`middleware/` 的模块划分，观察生产服务骨架如何拆分关注点。 |
| **ambersariya/cookiecutter-python**（[github.com/ambersariya/cookiecutter-python](https://github.com/ambersariya/cookiecutter-python.git)） | **最简洁克制的经典组合**：`Poetry` + `Ruff` + `MyPy --strict` + `Pytest`，`src/` 布局，`Makefile` 封装 `make check`，附 `AGENTS.md`。适合作为日常项目的干净起点。 |
| **fpgmaas/cookiecutter-uv**（[github.com/fpgmaas/cookiecutter-uv](https://github.com/fpgmaas/cookiecutter-uv.git)） | 轻量 uv 原生备选，适合快速起项目。 |

**阅读方法**：不需要运行模板。重点看 `pyproject.toml` 中各工具配置段、`Makefile` / `poe` 任务中的 `check` 流水线、`src/` 布局约定，以及 CI 文件中启用了哪些步骤。三份模板在核心工具选择上高度一致，差异在于严格程度与场景覆盖——这种“共识之上的谱系”正是本阶段最值得观察的。

---

### 阶段三：精读活跃的生产级项目（3–5 周）

**目标**：在真实、持续演进的代码库中，观察现代 Python 的接口设计、类型约束与工程组织。

**Web/API 方向：FastAPI**（[github.com/fastapi/fastapi](https://github.com/fastapi/fastapi.git)）

重点观察：基于类型注解的路由与请求体验证、Pydantic v2 深度集成、依赖注入系统设计、声明式 API 风格与性能的平衡。从一个最小 `APIRouter` 模块出发，跟踪“类型注解如何被转换为验证逻辑”这条主线。

配套应用样本：**adr1enbe4udou1n/fastapi-realworld-example-app**（[github.com/adr1enbe4udou1n/fastapi-realworld-example-app](https://github.com/adr1enbe4udou1n/fastapi-realworld-example-app.git)），覆盖 CRUD、认证、分页等真实场景。

**数据处理方向：Polars**（[github.com/pola-rs/polars](https://github.com/pola-rs/polars.git)）

重点观察 Python 接口层（而非 Rust 核心）：惰性求值、表达式系统、查询优化如何被表达；用 Python 类型系统表达列式计算 schema 的方式；与 pandas“急切求值 + 索引”哲学的对照。可配合 `ludo-technologies` 的 `data-science` skill（向量化、`.loc` 而非链式索引、显式 dtype、边界校验）对照阅读。

---

### 阶段四：工程化视野与持续发现（可与阶段三并行）

**目标**：把“结构清晰”从模糊印象变成可识别、可复用的模式。

- **持续索引：lukasmasuch/best-of-python**：按领域（Web、数据、CLI、测试等）筛选当前评分最高的库，作为下一个精读候选。
- **宏观路线参照：Python-100-Days**：章节划分适合作为“接下来该补什么”的检查清单，而非精读材料。

---

## 三、系统化学习链接汇总

**主动练习**

- pythonlings：[github.com/abhiksark/pythonlings](https://github.com/abhiksark/pythonlings.git)
- Farc726/Python-Learning：[github.com/Farc726/Python-Learning](https://github.com/Farc726/Python-Learning.git)

**风格参照与 Skills**

- nathan-gage/python-skills：[github.com/nathan-gage/python-skills](https://github.com/nathan-gage/python-skills.git)
- ludo-technologies/python-best-practices：[github.com/ludo-technologies/python-best-practices](https://github.com/ludo-technologies/python-best-practices.git)
- [danicat/skills](https://github.com/danicat/skills.git)（`pyhd` skill）

**工程模板（Cookiecutter）**

- bwrob/zenith：[github.com/bwrob/zenith](https://github.com/bwrob/zenith.git)
- ByronWilliamsCPA/cookiecutter-python-template：[github.com/ByronWilliamsCPA/cookiecutter-python-template](https://github.com/ByronWilliamsCPA/cookiecutter-python-template.git)
- ambersariya/cookiecutter-python：[github.com/ambersariya/cookiecutter-python](https://github.com/ambersariya/cookiecutter-python.git)
- fpgmaas/cookiecutter-uv：[github.com/fpgmaas/cookiecutter-uv](https://github.com/fpgmaas/cookiecutter-uv.git)

**精读项目**

- FastAPI：[github.com/fastapi/fastapi](https://github.com/fastapi/fastapi.git)
- Polars：[github.com/pola-rs/polars](https://github.com/pola-rs/polars.git)
- fastapi-realworld-example-app：[github.com/adr1enbe4udou1n/fastapi-realworld-example-app](https://github.com/adr1enbe4udou1n/fastapi-realworld-example-app.git)

**持续索引与路线参照**

- [lukasmasuch/best-of-python](https://github.com/lukasmasuch/best-of-python.git)
- [Python-100-Days](https://github.com/jackfrued/Python-100-Days.git)

---

## 四、核心建议

**最精简的起步组合**：pythonlings（主动修复建立手感）→ 精读 `bwrob/zenith` 的 `pyproject.toml` 与 `poe` 任务定义（理解严格质量门禁如何落地）→ 用 `nathan-gage/python-skills` 的规则作为写代码时的即时检查清单 → FastAPI 或 Polars 选其一精读（观察真实项目的类型与接口设计）。

**让工具链成为第一审查者**：从一开始就启用 `ruff` 与 `mypy --strict`，把每条警告当作风格反馈来阅读和修复，而不是等项目写完再统一处理。

**让 skills 规则集成为第二审查者**：工具链负责语法与类型层面的正确性，skills 规则负责设计决策层面的信号。当 `ruff` 提示未使用变量时，数据建模规则可能同时指出某个可变默认值在共享状态下是设计缺陷；当 `mypy` 放过一个 `Any` 时，类型安全规则会提醒“精确类型优于 `Any`，修复优于忽略”。两者结合，比依赖任何单一来源都更接近“写得像现代 Python”的目标。