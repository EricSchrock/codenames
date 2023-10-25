# Step 2

## Refining your game loop

Almost all computer games have some version of a game loop. They generally look something like this.

```c
while (true) {
    process_input();
    update_state();
    render();
}
```

Clear separation between the code from each of these three steps comes with a lot of benefits. Adding support for multiple types of input devices (e.g. mouse and keyboard vs controller) only has to touch the `process_input()` code. You can write tests purely for your game logic `update_state()` without worrying about your I/O code, as we will do in the next step. You can write the `process_inputs()` and `render()` steps in Python and the `update_state()` step in C, as we will do in a later step. You can switch from a TUI (text user interface) that uses a terminal command line for I/O to a GUI (graphical user interface) that uses a window with clickable entities like buttons without touching the `update_state()` step, as we will do sometime in the future. If the properties listed above do not hold for your code, your game loop steps are not properly isolated.

The article linked below explains game loops in detail. You do not have to worry about the time related portions yet for your Codenames TUI, as it probably currently pauses in the `process_input()` step to wait for user input and only updates and renders the state in response to new input. This will change once you transition to a GUI.

https://gameprogrammingpatterns.com/game-loop.html

See the links below for examples of game loops in C/C++ code. The first is a TUI. The second is a GUI with an FPS (frames per second) throttle.

https://github.com/EricSchrock/tic-tac-toe/blob/master/tic_tac_toe_tui.c

https://github.com/EricSchrock/acquire (see the source code and the diagrams in the README)

    Objective: Refactor your code into a clear game loop

As always, create a new branch off `main` for your changes and once you have them working, submit a PR (pull request) into `main` and set me as a reviewer.
