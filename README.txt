


2 week Group Member Contributions:
Together in person, both members discussed and worked out the strategy that they wanted to use, writing up pseudocode on a whiteboard. They started directly with the strategy using the minimax decision tree. This was thought through using a heuristic, in which they planned on giving point values to potential moves trrying to maximize the minimum gain. Both members initially did commits of smaller significance. After, Ruoyun used the pseudocode to code the strategy in C++. 

Strategy Improvements:
We initially started off by getting our AI to simply work. With the array of valid moves, we simply had our bot choose the first valid move found and to use that move in the next turn. From there, we improved out bot by implementing the minimax decision tree strategy to look into the future of possible moves and to choose the move that maximized our minimum gain following the opponent's possible moves. The depth of the minimax was initially 2, which was then changed to 4 to get a better idea of how the game would turn out following certain moves. Lastly, we added one more thing to our heuristic. We added to our score not only for the minimum gain but also for how many possible choices our bot would have in the future. The more choices of moves, the more likely it is for the bot to have a good move to do, thus increasing chances of winning. 