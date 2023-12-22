# Step 1

## Setting up your environment

### Windows Subsystem for Linux (WSL)

Why Linux? Because everything required for C development is either preinstalled or easily installable from the command line. For this and other reasons, Linux is very common in industry.

Why WSL? Because it is the easiest way to develop in Linux on a Windows computer.

[ ] Install WSL2 and Ubuntu

> [!NOTE]
> https://learn.microsoft.com/en-us/windows/wsl/install

### Visual Studio Code (VS Code)

Why VS Code? Because it is currently the most commonly used code editor. It also integrates with WSL.

[ ] Install and setup VS Code

> [!NOTE]
> - https://code.visualstudio.com/
> - https://code.visualstudio.com/learn/get-started/basics

[ ] Install the Microsoft extensions for Python and C/C++ development

> [!NOTE]
> https://code.visualstudio.com/learn/get-started/extensions

[ ] Connect VS Code to WSL

> [!NOTE]
> https://learn.microsoft.com/en-us/windows/wsl/tutorials/wsl-vscode

## Setting up version control

### GitHub

Why GitHub? A free GitHub account allows free private and public code repositories.

    Objective: Create a GitHub account

https://github.com/

Your GitHub account is a key part of your professional portfolio. I recommend you tie your username to your real name (e.g. mine is EricSchrock). This makes it easier for people to find you online and also makes it easier for people to type in your GitHub account link when looking off a paper copy of your resume (e.g. https://github.com/EricSchrock). If you already have a GitHub account, it is easy to change your username.

https://docs.github.com/en/account-and-profile/setting-up-and-managing-your-personal-account-on-github/managing-user-account-settings/changing-your-github-username

    Objective: Complete the "hello world" tutorial

https://docs.github.com/en/get-started/quickstart/hello-world

    Objective: Create a public GitHub repository called "codenames"

The most common naming convention for repositories is all lowercase letters with dashes in place of spaces (e.g. `purdue-ece437` or `tic-tac-toe`).

A good rule of thumb is to keep repositories tied to generic class assignments private so people can't cheat off you and to keep everything else public to build your professional portfolio. Class projects that are unique to you or your team can be kept public.

### git

Why git? Because unfortunately, [mercurial](https://www.mercurial-scm.org/) is dead.

Why version control? Version control saves the history of your code changes and enables smoother collaboration with tools for merging changes to the same files by multiple people.

    Objective: Complete a git tutorial

https://www.freecodecamp.org/news/learn-the-basics-of-git-in-under-10-minutes-da548267cc91/

    Objective: Setup an authenticated connection between your computer and GitHub

https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account?platform=linux

This part can be pretty tricky. Don't be afraid to ask for help!

    Objective: Clone your "codenames" GitHub repository

Enter `git clone git@github.com:<your username>/codenames.git` on the WSL command line.

    Objective: Open the cloned repository in VS Code

Click `File` -> `Open Folder...` or press `Ctrl + K` follow by `Ctrl + O`.

## Saving your code baseline

    Objective: Create a branch called "baseline" and commit your Python Codenames project code

1. From your WSL terminal, in your `codenames` git repository clone, run `git checkout -b baseline`.
2. Put your Python Codenames project code inside your `codenames` repository.
3. Commit your code by running `git add *` followed by `git commit -m "Baseline Python code"`.

Git commands can be tricky. Reach out if you need any help!

    Objective: Install the Pylint VS Code extension, fix all warnings in your Python code, and commit your changes

Pylint will put wiggly lines under lines of code with warnings. Hover over the line to get a popup explaining the warning.

Linting is a form of static analysis. Static analysis is any automated error checking that can be done without running your code. This is as opposed to dynamic analysis.

    Objective: Create a pull request (PR)

https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/requesting-a-pull-request-review

    Objective: Resolve any feedback I give and ask for a re-review. Repeat until everything looks good and then merge the PR.

For the rest of the project, do your work in branches off the `main` branch and use PRs reviewed by me to merge those branches back to `main`.
