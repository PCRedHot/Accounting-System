# Accounting System

> This is a group project from HKU ENGG1340 Group 120

---

## Table of content

- [Problem Statement](#problem-statement)
- [Problem Setting](#problem-setting)
- [Teammembers](#teammembers)

---

## Problem Statement

Living in high-paced life with much pressure, people need dealing with their balance of payments data from all kinds of area to evaluate personal financial status every day, which will be extraordinarily complicated and time-consuming tasks in case operated by traditional accounting methods. Thus, a more visual and efficient accounting system aimed at solving personal financial data’s tracking and management is in sore demand.

---

## Problem Setting


### Introduction


The Accounting System focus on helping manage personal wealth efficiently.

It will provide advanced accounting operations for users, making them able to create new accounts, and further add or modify records stored in the current accounts. The system will also output the records so far, as well as statistic data of the wealth, on the demand of the users.

![](https://img.shields.io/badge/Language-C++-brightgreen.svg)


### Features


The system receives user input with different information, and launchs relevant function to store them.

	1. Set name and balance for initial accounts
	2. Add records of transaction
	3. Delete and edit

&nbsp;

Feature | Purpose
------------- | -------------
Set name and balance  | Create initial accounts which can be further operated
Add records of transaction  | Record income and expense of multiple categories from different accounts
Delete and edit | Access and modify records easily

&nbsp;

Also, the system outputs multiple statistic reports which are calculated based on the existing data. Additionally, it will evaluate the general financial status of the user.

	4. List the record
	5. Statistic reports
	6. Evaluation

&nbsp;

Feature | Purpose
------ | ------
List the record | View previous transactions with accounts, date, amount or category (all or part)
Statistic reports | Give report of users' financial state in detail, about income and expenditure, proportion and variation
Evaluation | Briefly evaluate wealth states

&nbsp;

Besides, the accounting system provides practical and user-friendly functions

	7. Budget and alert

&nbsp;

Feature | Purpose
------ | ------
Budget and alert | Alert the user if total expenditure exceeds default budget

&nbsp;

The system will launch more incredible features in the comming soon.

---

## Usage


###Step 1. Makefile


If users use Accounting System for the first time, it's necessary to compile the executable programs from source files by reading Makefile.

Users can type in the command below to compile run.cpp

    $ make run

If succeed, users' terminal will display compilation process shown below

		g++ -c run.cpp
		g++ -c account.cpp
		g++ -c accountlib.cpp
		g++ -c transaction.cpp
		g++ -c tranlib.cpp
		g++ -c AccountingSystem.cpp
		g++ run.o account.o accountlib.o transaction.o tranlib.o AccountingSystem.o -o run



## Teammembers

| **CHOI Chong Hing** | **CHEN Xingsheng** |
| :---: |:---:|
| 3035564940 | 3035535547 |
| [![CHOI Chong Hing](https://i.imgur.com/elZNX0z.jpg)](https://github.com/PCRedHot)    | [![CHEN Xing Sheung](https://i.imgur.com/xasWEFT.jpg)](https://github.com/XsChen524) |
| <a href="https://github.com/PCRedHot" target="_blank">`github.com/PCRedHot`</a> | <a href="https://github.com/XsChen524" target="_blank">`github.com/XsChen524`</a> |
