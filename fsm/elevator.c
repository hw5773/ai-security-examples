#include <stdio.h>
#include "states.h"

int get_command(void)
{
  int cmd;
  printf("Please insert a command (0: quit, 1: up, 2: down)\n");
  scanf("%d", &cmd);
  return cmd;
}

int main(int argc, char *argv[])
{
  int cmd, state;

  state = STATE_GROUND;

  while (1)
  {
    cmd = get_command();
    if (!cmd)
      break;

    switch (state)
    {
      case STATE_GROUND:
        printf("We are at the ground floor\n");
        if (cmd == INPUT_UP)
        {
          printf("The elevator is moving up...\n");
          state = STATE_FIRST;
          printf(" - Red: off, Green: on\n");
          printf("The elevator is reached to the first floor\n");
        }
        else if (cmd == INPUT_DOWN)
        {
          printf("The down button is not allowed at the ground floor\n");
          state = STATE_GROUND;
        }
        break;

      case STATE_FIRST:
        printf("We are at the first floor\n");
        if (cmd == INPUT_UP)
        {
          printf("The up button is not allowed at the first floor\n");
          state = STATE_FIRST;
        }
        else if (cmd == INPUT_DOWN)
        {
          printf("The elevator is moving down...\n");
          state = STATE_GROUND;
          printf(" - Red: on, Green: off\n");
          printf("The elevator is reached at the ground floor\n");
        }
        break;

      default:
    }
  }
}
