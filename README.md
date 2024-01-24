# TicTacToe

This is a basic Tic-Tac-Toe game where where the AI never loses. The algorithm used for the AI is minimax

## Algorithm Description

The Minimax algorithm is a decision-making algorithm frequently employed in Tic-Tac-Toe, a two-player turn-based game. The primary goal is to determine the optimal move for a player, considering that both players aim to make the best moves possible. The Minimax algorithm systematically explores the game's possible moves, creating a decision tree that outlines various game states and potential outcomes.

Here's a more detailed breakdown of its functionality:

Game Tree Generation:
- The Minimax algorithm generates a comprehensive game tree that encompasses all feasible moves and potential game states in Tic-Tac-Toe.
- This tree is constructed by recursively examining all possible moves from the current state of the Tic-Tac-Toe board.
Assigning Values:
- Each terminal state in the game tree is assigned a value based on the outcome: +1 for a win, -1 for a loss, and 0 for a draw.
These values reflect the desirability of the respective outcomes from the perspective of the current player.
Backpropagation:
- The values assigned to terminal states are then propagated up the tree to identify the optimal move for each player.
Maximizing players (e.g., the computer in Tic-Tac-Toe) select the move with the maximum value among their children.
Minimizing players (e.g., the human opponent) choose the move with the minimum value among their children.

Decision-Making:
- The root of the tree corresponds to the current state of the Tic-Tac-Toe board. The Minimax algorithm selects the move that leads to the child node with the highest value for the maximizing player.

## Usage

Run the TicTacToeApp.exe
