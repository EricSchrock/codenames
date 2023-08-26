# Week 2 (August 27 - September 2, 2023)

## Refining your game loop

Almost all computer games have some version of a game loop. They generally look something like this.

```c
while (true) {
    process_input();
    update_state();
    render();
}
```

Clear separation between the code from each of these three steps comes with a lot of benefits. Adding support for multiple types of input devices (e.g. mouse and keyboard vs controller) only has to touch the `process_input()` code. You can write tests purely for your game logic `update_state()` without worrying about your I/O code, as we will do this week. You can write the `process_inputs()` and `render()` steps in Python and the `update_state()` step in C, as we will do next week. You can switch from a TUI (text user interface) that uses a terminal command line for I/O to a GUI (graphical user interface) that uses a window with clickable entities like buttons without touching the `update_state()` step, as we will do sometime in the future. If the properties listed above do not hold for your code, your game loop steps are not properly isolated.

The article linked below explains game loops in detail. You do not have to worry about the time related portions yet for your Codenames TUI, as it probably currently pauses in the `process_input()` step to wait for user input and only updates and renders the state in response to new input. This will change once you transition to a GUI.

https://gameprogrammingpatterns.com/game-loop.html

See the links below for examples of game loops in C/C++ code. The first is a TUI. The second is a GUI with an FPS (frames per second) throttle.

https://github.com/EricSchrock/projects-for-luke/blob/master/tic_tac_toe_tui.c

https://github.com/EricSchrock/acquire (see the source code and the diagrams in the README)

    Objective: Refactor your code into a clear game loop

As always, create a new branch off `main` for your changes and once you have them working, submit a PR (pull request) into `main` and set me as a reviewer.


&nbsp;
## Adding tests to your code

Creating tests that can be rerun easily allow you to confidently make changes while ensuring you don't break key requirements. There are lots of different kinds of testing, but three common types are system, integration, and unit tests. In particular, these three types of tests are three different levels of testing that are often paired together. System tests test an entire system as a whole. Integration tests test that multiple pieces of code, often called modules, work together as expected. Unit tests test individual units of code in isolation, where units are usually individual functions.

Writing automated tests for I/O can be tricky, so for this week our goal is to write unit tests for your "state update" code. If you've properly defined your game loop, you should be able to do this without touching your "process input" or "render" code.

The article linked below lays out some unit testing best practices. Over time, you'll develop an intuition for the right level of testing for each context, but this should give you a foundation to start from. Don't worry too much about the more complicated techniques the article discusses like mocking or dependency injection.

https://learn.microsoft.com/en-us/dotnet/core/testing/unit-testing-best-practices

`pytest` is an easy way to add tests to Python projects. See the links below for a setup tutorial and some example tests from one of my personal projects.

https://docs.pytest.org/en/7.1.x/getting-started.html

https://github.com/EricSchrock/zurg (see `tests/zurg_test.py`)

    Objective: Write tests for the functions tied to your state update code

As always, create a new branch off `main` for your changes and once you have them working, submit a PR (pull request) into `main` and set me as a reviewer.
