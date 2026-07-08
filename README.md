_This project has been created as part of the 42 curriculum by mgadzhim._

# Philosophers

## Description

A C implementation of the classic **dining philosophers problem**: N
philosophers sit at a round table with one fork between each pair. To eat,
a philosopher needs both neighboring forks; the rest of the time they sleep
and think. A philosopher who does not start eating within `time_to_die`
milliseconds of their last meal dies, and the simulation ends.

Each philosopher runs as a separate **thread**, and every fork is protected
by a **mutex**. A monitor loop in the main thread watches each philosopher's
last-meal timestamp and announces a death within 10 ms of when it occurs.
Deadlock is prevented by breaking lock-order symmetry: even-numbered
philosophers pick up their forks in the opposite order from odd-numbered
ones, so a circular wait can never form. The program contains no global
variables and no data races (verified with ThreadSanitizer), and frees all
allocated memory (verified with AddressSanitizer).

## Instructions

### Compilation

```bash
cd philo
make
```

Builds the `philo` executable with `cc -Wall -Wextra -Werror`.

### Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

All times are in milliseconds. If the optional fifth argument is given, the
simulation stops once every philosopher has eaten at least that many times;
otherwise it runs until a philosopher dies.

### Examples

```bash
./philo 5 800 200 200      # runs until interrupted, nobody should die
./philo 4 310 200 100      # a philosopher dies
./philo 5 800 200 200 7    # stops after everyone has eaten 7 times
./philo 1 800 200 200      # one philosopher, one fork: dies at ~800 ms
```

Each state change is logged as `timestamp_in_ms X <state>`, where states are
`has taken a fork`, `is eating`, `is sleeping`, `is thinking`, and `died`.

## Technical choices

- **One thread per philosopher, one mutex per fork**, as required by the
  subject.
- **Monitor in the main thread**: philosophers only eat/sleep/think; a
  single monitor sweeps all last-meal timestamps every millisecond, sets a
  mutex-protected stop flag, and prints the death message. This keeps death
  detection independent of a starving philosopher's own (possibly blocked)
  thread.
- **Shared state under dedicated mutexes**: meal data (`meal_lock`), the
  stop flag (`stop_lock`), and console output (`write_lock`). The death
  announcement is ordered after the stop flag is set, so no state message
  can appear after `died`.
- **Sliced sleeping**: waiting is done in short `usleep` bursts with elapsed
  time checks, keeping timing error well inside the 10 ms reporting budget.

## Resources

- [Dining philosophers problem — Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX threads programming guide (LLNL tutorial)](https://hpc-tutorials.llnl.gov/posix/)
- `man pthread_create`, `man pthread_mutex_init`, `man gettimeofday`,
  `man usleep`
- **AI usage**: an AI assistant (Claude) was used to explain the underlying
  concepts (threads, mutexes, data races, deadlock avoidance, monitor
  design), to review each development iteration for norm issues and
  edge cases, which were then reviewed, integrated, and tested by the
  author. All design decisions and final code are understood and owned by
  the author.
