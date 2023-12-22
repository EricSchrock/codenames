# Step 3

## Adding tests to your code

Creating tests that can be rerun easily allow you to confidently make changes while ensuring you don't break key requirements. There are lots of different kinds of testing, but three common types are system, integration, and unit tests. In particular, these three types of tests are three different levels of testing that are often paired together. System tests test an entire system as a whole. Integration tests test that multiple pieces of code, often called modules, work together as expected. Unit tests test individual units of code in isolation, where units are usually individual functions.

Writing automated tests for I/O can be tricky, so for this step our goal is to write unit tests for your "state update" code. If you've properly defined your game loop, you should be able to do this without touching your "process input" or "render" code.

[This article](https://learn.microsoft.com/en-us/dotnet/core/testing/unit-testing-best-practices) lays out some unit testing best practices. Over time, you'll develop an intuition for the right level of testing for each context, but this should give you a foundation to start from. Don't worry too much yet about the more complicated techniques the article discusses like mocking or dependency injection.

- [ ] Learn how to use `pytest` (a test framework for Python)
  - https://docs.pytest.org/en/7.1.x/getting-started.html
- [ ] Write tests for the functions tied to your state update code. Below are some example tests from one of my personal projects.
  - https://github.com/EricSchrock/zurg/blob/main/tests/zurg_test.py

> [!IMPORTANT]
> As always, create a new branch off `main` for your changes and once you have them working, submit a PR (pull request) into `main` and set me as a reviewer.
