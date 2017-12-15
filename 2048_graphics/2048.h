class Game{
    
    public:
    static const int BOARD_WIDTH=4;
    static const int BOARD_HEIGHT=4; // should have used just one, since the board is square
    static const int SCR_WIDTH = 600; // playing window width
    static const int SCR_HEIGHT = 700; // playing window height
    int score = 0;
    int board[BOARD_WIDTH][BOARD_HEIGHT] = {0}; // declare the board and fill it with zeros
    int bck_board[BOARD_WIDTH][BOARD_HEIGHT] = {0}; // backup used to clone the board so we can rotate it
    int random_number(); // 90% chance of 2; 10% chance of 4
    int random_index(); // random position on the board
    void Start_Board(); // populate board
    int Check_Max(); // maybe later
    void Rotate_Clockwise(int times);
    void Rotate_Counterclockwise(int times);
    void Push_Tiles();
    void Add_Tiles();
    void Check_Win_Lose(); // check if you won or lost
    void Add_New_Number(); // add new number to the board in random position
    void Draw_Board(); // draw the board
};