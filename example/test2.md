# Kotlin → Android 8 周精细日程（按天）

下面把你给的 8 周计划细化到**每天要做的具体任务**（工作日 + 周末）。我假设每周从周一开始。每个工作日建议投入 **1–2 小时**（快进/复盘可以更短），周末建议 **3–5 小时** 完成实战与回顾。若你有特定起始日期，我可以把“周一/周二”替换为具体日期；现在先按星期来精排。

------

## 第1周（Kotlin 基础 — 语法、类型与控制流）

**目标：** 掌握变量、基本类型、控制流与空安全。

- 周一（周1）
  - 学习 `val` vs `var`、基本数值类型（Int/Long/Float/Double）、布尔、Char、String。
  - 练习：写小程序打印不同类型变量和字符串模板（`"Hello $name"`）。
- 周二（周2）
  - 学习函数定义（参数、默认值、命名参数、返回类型）。
  - 练习：写 3 个函数：求和、求阶乘、判断质数。
- 周三（周3）
  - 学习 `if` 表达式（作为表达式使用）与 `when`（替代 switch，匹配类型/范围/集合）。
  - 练习：写使用 `when` 的成绩分级函数（90+ A，80-89 B 等）。
- 周四（周4）
  - 学习循环：`for`（range 与 集合）、`while`、`do-while`。
  - 练习：用 `for` 生成斐波那契前 N 项并打印。
- 周五（周5）
  - 学习 Null 安全：`?`、`?:`（Elvis）、`!!`、安全调用 `?.`、安全类型转换 `as?`。
  - 练习：实现一个接收可能为 null 的字符串并返回长度（安全写法 + 非安全写法比较）。
- 周六（周6 — 实战）
  - **实战：简单计算器（控制台）**：要求支持 `+ - * /` 和错误处理（除以 0、非法输入）。
  - 交付：可运行的 Kotlin 脚本或小主函数，包含输入提示与结果输出。
- 周日（周7 — 回顾 + 扩展）
  - 回顾一周笔记，重构计算器：添加浮点支持与运算符优先级（可选）。
  - 小挑战：添加对括号的简单支持（如果时间足够）。

------

## 第2周（Kotlin — 集合与 Lambda）

**目标：** 熟练使用集合类型与高阶函数。

- 周一
  - 学习集合类型：只读 `List/Set/Map` 与可变 `MutableList/MutableSet/MutableMap`。
  - 练习：创建不同集合并进行增删查（可变/不可变对比）。
- 周二
  - 学习 Lambda 语法（参数 -> 表达式）与匿名函数。
  - 练习：写几个 lambda，如 `val square = { x: Int -> x*x }`。
- 周三
  - 学习集合常用高阶函数：`map`, `filter`, `forEach`, `find`, `flatMap`。
  - 练习：对一个整数列表，先 `map` 平方再 `filter` 偶数。
- 周四
  - 学习聚合函数：`reduce`, `fold`, `sumBy` / `sumOf`。
  - 练习：计算字符串列表拼接、求分数总和与平均数（注意空列表处理）。
- 周五
  - 学习序列（`sequence`）与惰性计算的基本概念（当数据很大时使用）。
  - 练习：比较 `list.map().filter()` 与 `sequence` 的用法（概念理解即可）。
- 周六（实战）
  - **实战：学生筛选程序**：输入或硬编码学生列表（name, score），用 `filter` 筛选及格（>=60），用 `average()` 打印平均分，并按姓名排序输出。
  - 交付：带单元或 main 测试用例。
- 周日（回顾 + 优化）
  - 回顾代码，添加异常/空列表处理并写注释。
  - 小挑战：用 `groupBy` 按成绩段分组（A/B/C/D/F）并统计每组人数。

------

## 第3周（Kotlin — 类与数据结构）

**目标：** 掌握面向对象、数据类与常用模式。

- 周一
  - 学习 `class` 定义、主构造函数与次构造、属性（`val/var`）与初始化块 `init`。
  - 练习：写一个 `Person` 类带属性和方法（如 `greet()`）。
- 周二
  - 学习继承、`open`、`override`、`super`。
  - 练习：实现 `Animal` 基类并派生 `Dog`/`Cat` 覆盖 `sound()` 方法。
- 周三
  - 学习 `data class`（自动 `equals`/`hashCode`/`toString`/`copy`）与解构声明。
  - 练习：写 `data class Point(val x:Int, val y:Int)` 并演示 `copy()`。
- 周四
  - 学习 `interface` 与接口默认实现、`sealed class`（受限继承）与 `object`（单例）。
  - 练习：写一个 `sealed class Result`（`Success`/`Error`）并在 `when` 中处理。
- 周五
  - 学习扩展函数/属性与委托属性（`by lazy` 简介）。
  - 练习：为 `String` 写扩展函数 `isPalindrome()`。
- 周六（实战）
  - **实战：简单博客系统模拟**：使用 `data class User/ Post/ Comment`，实现创建样例数据、打印用户发布的文章及评论汇总。
  - 交付：主函数展示数据关系（例如列出每篇文章的评论数量）。
- 周日（回顾 + 小改进）
  - 回顾并用 `sealed class` 表示帖子状态（Draft/Published/Deleted）。
  - 小挑战：实现按作者分组显示文章，并用 `copy()` 更新文章状态。

------

## 第4周（Kotlin — 协程基础）

**目标：** 理解协程模型与常见 coroutine API 用法。

- 周一
  - 学习并发 vs 异步 的概念，协程的基本思想。阅读 `kotlinx.coroutines` 概览。
  - 练习：在 `runBlocking` 中启动一个简单协程打印日志。
- 周二
  - 学习 `suspend` 函数、`delay`（代替 Thread.sleep）与 `launch`。
  - 练习：用 `launch` 启动若干协程并观察并发输出顺序。
- 周三
  - 学习 `async` + `await`（`Deferred`），如何并行获取结果。
  - 练习：用 `async` 并发计算两个耗时任务并合并结果。
- 周四
  - 学习 `withContext` 切换调度器（`Dispatchers.Default/IO/Main` 概念）。
  - 练习：在 `withContext(Dispatchers.IO)` 中模拟 IO 操作（如读文件）。
- 周五
  - 学习协程的异常处理（`CoroutineExceptionHandler`）、取消与超时（`withTimeout`）。
  - 练习：给并发任务加上超时保护并处理取消。
- 周六（实战）
  - **实战：模拟并发下载与 API 汇总**：
    - 使用 `launch` + `delay` 模拟同时下载 3 个文件（每个下载打印开始/结束）。
    - 使用 `async` 模拟并发请求两个 API（返回数字），等待并打印两者之和。
  - 交付：可运行示例，展示日志和结果。
- 周日（回顾 + 扩展）
  - 回顾协程生命周期与常见陷阱（如忘记取消、阻塞主线程）。
  - 小挑战：将“并发下载”改为并发限制（例如同时最多 2 个并发）——可用 `Semaphore` 或自建队列。

------

## 第5周（Android — Studio 与项目结构）

**目标：** 熟悉 Android 项目结构与常用资源/配置。

- 周一
  - 安装/打开 Android Studio，创建新项目（Kotlin 模板）。浏览项目结构（`app/src/main`、`res`、`manifests`）。
  - 练习：定位 `AndroidManifest.xml`，查看 Activity 声明与权限。
- 周二
  - 学习 `build.gradle.kts`（模块与项目）、依赖添加与同步。
  - 练习：向 `build.gradle.kts` 添加一个常用库（例如 Coroutines 或 Jetpack Compose 依赖），同步构建。
- 周三
  - 学习资源文件夹：`drawable`（图片/shape）、`layout`、`values/strings.xml/colors.xml/styles.xml`。
  - 练习：在 `strings.xml` 添加字符串资源并在布局中引用。
- 周四
  - 学习 `themes`/`styles`（Material 主题基础）。
  - 练习：修改主题颜色并观察预览变化。
- 周五
  - 学习 `Activity` 与 `Context` 的基本概念，以及如何找到 View（`findViewById` / ViewBinding 简介）。
  - 练习：在 Activity 中打印 `this` 与 `applicationContext` 的区别（日志）。
- 周六（实战）
  - **实战：新项目 + 按钮与文本框**：创建一个按钮和一个文本控件，点击按钮改变文本内容（在布局 xml + Activity 中实现）。
  - 交付：运行在模拟器/真机，记录操作步骤。
- 周日（回顾 + Debug）
  - 回顾日志（Logcat），学会查看崩溃堆栈与常见错误修复。
  - 小挑战：给按钮添加简单输入验证（例如文本为空时 Toast 提示）。

------

## 第6周（Android — Activity 生命周期与 Intent）

**目标：** 深入理解 Activity 生命周期并能用 Intent 在 Activity 之间传递数据。

- 周一
  - 背诵并理解 Activity 生命周期回调：`onCreate` → `onStart` → `onResume` → `onPause` → `onStop` → `onDestroy`，及 `onRestart`。
  - 练习：在每个回调中 `Log.d()` 打印信息。
- 周二
  - 学习显式 Intent（在同一应用内跳转）与隐式 Intent（系统/外部 app）。
  - 练习：写显式 Intent 跳转代码框架 `startActivity(Intent(this, B::class.java))`。
- 周三
  - 学习如何通过 Intent 传递数据（`putExtra`/`getStringExtra`）和使用 `Parcelable` / `Serializable` 传复杂对象（概念）。
  - 练习：简单传递字符串/整数并接收显示。
- 周四
  - 学习屏幕旋转导致的 Activity 重建与状态保存（`onSaveInstanceState` / `onRestoreInstanceState`）。
  - 练习：在旋转后保持一个计数器的值。
- 周五
  - 学习任务与返回栈（Back Stack）基本概念与 `finish()`。
  - 练习：观察按返回键时 Activity 的日志序列。
- 周六（实战）
  - **实战：两个 Activity 传参并观察生命周期**：A 有按钮点击跳转到 B 并传字符串；B 显示字符串并在日志打印所有生命周期方法。试验屏幕旋转、按返回。
  - 交付：记录测试步骤与你观察到的生命周期变化。
- 周日（回顾 + 错误排查）
  - 回顾 Intent 传参的边界情况（null/类型不匹配）。
  - 小挑战：实现从 B 返回数据到 A（`startActivityForResult` 或新的 ActivityResult API）。

------

## 第7周（Android — 传统 UI（XML）速览）

**目标：** 理解常用布局与列表需求。

- 周一
  - 学习 `LinearLayout`（方向、权重 `layout_weight`）。
  - 练习：用 LinearLayout 做水平/垂直排列示例。
- 周二
  - 学习 `FrameLayout`（叠放）与 `RelativeLayout`（或 ConstraintLayout 的基本用法）。
  - 练习：用 FrameLayout 叠放文本在图片上。
- 周三
  - 学习 `ConstraintLayout` 基础（约束、Chain、Guideline）。
  - 练习：用 ConstraintLayout 实现简单响应式布局（图+标题+按钮）。
- 周四
  - 学习为什么需要 `RecyclerView`（性能、复用），理解 Adapter/ViewHolder 模型。
  - 练习：阅读 RecyclerView 最小用法（不必手写完整实现）。
- 周五
  - 学习布局优化与测量、布局通道常见问题（如 match_parent/wrap_content 的差异）。
  - 练习：修复一个常见布局抖动/溢出问题的案例（实践题）。
- 周六（可选实战）
  - **实战（可选）：用 XML 实现登录界面**：手机号/密码输入框、登录按钮、记住我复选框。
  - 交付：带基本表单校验（非空、格式）。
- 周日（回顾 + 迁移思考）
  - 回顾 XML 布局重点，为后续 Compose 对应概念做映射（比如 ConstraintLayout ↔ Box/Row/Column）。
  - 小挑战：将登录界面的布局思路写成 Compose 伪代码（便于 Week8 对比）。

------

## 第8周（Android Compose — 列表 LazyColumn）

**目标：** 用 Jetpack Compose 构建联系人列表（替代 RecyclerView 思路）。

- 周一
  - 学习 Compose 基础：`@Composable`、`setContent`、`Column`、`Row`、`Text`、`Button`。
  - 练习：写一个简单的 `Greeting(name: String)` composable 并在 Activity 中显示。
- 周二
  - 学习状态管理基础（`remember`、`mutableStateOf`）与 Compose 的单向数据流。
  - 练习：实现一个计数器 composable（按钮增加计数）。
- 周三
  - 学习 `LazyColumn`/`LazyRow` 基本用法与 item 排版（item、itemsIndexed）。
  - 练习：用 `LazyColumn` 渲染一个静态字符串列表。
- 周四
  - 学习可复用的 list item 组件构建（头像 + 名称 + 电话），与点击事件处理。
  - 练习：实现 `ContactRow(contact: Contact, onClick: ...)` composable。
- 周五
  - 学习简单的列表性能技巧（keying，避免重组）与分割线/空视图处理。
  - 练习：给 `LazyColumn` 增加 `key = { it.phone }` 并加 Divider。
- 周六（实战）
  - **实战：通讯录列表小项目**：
    - 使用 `data class Contact(name: String, phone: String)` 的静态数据（10–20 条）。
    - 使用 Compose + `LazyColumn` 显示联系人列表；点击某项弹出详情（例如 `Snackbar` 或导航到详情 composable）。
  - 交付：代码在模拟器上运行并截图（或记录运行步骤）。
- 周日（回顾 + 下一步建议）
  - 总结两个月所学，列出你想接着学的方向（例如：网络请求 + Room 存储 + 图片加载 + Navigation Compose）。
  - 小挑战：把联系人数据抽成 ViewModel（如果熟悉）或至少做一个简单搜索过滤（在 UI 上加文本框过滤联系人）。

------

## 额外建议（进度与复盘）

- 每日结束花 **10–15 分钟** 写学习笔记（遇到的问题与解决方法），周末花 **30 分钟** 做周复盘并把代码整理到一个 Git 仓库。
- 若时间允许：在每周的周日把该周的“实战”代码提交到 GitHub，并写一个小 README（目的、运行方法、遇到的坑）。
- 如果你想我把这个计划映射到具体日期（例如从 2025-11-17 开始），告诉我起始周的**具体周一日期**，我会把每个“周一/周二...”替换成具体日期并返回一份可打印的日历式清单。

需要我现在把这个按你给定的开始日期/每天可投入时间（比如每天 1.5 小时）转成带具体日期的日历计划吗？