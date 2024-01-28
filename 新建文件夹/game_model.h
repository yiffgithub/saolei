#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>

// 方块的状态
enum class BlockState {
    UN_DIG,
    DIGGED,
    MARKED,
    BOMB,
    WRONG_BOMB
};

// 雷方块类
struct MineBlock {
    BlockState curState; // 当前状态
    int valueFlag;       // 数值，0到8，-1表示雷
};

// 游戏状态
enum class GameState {
    PLAYING,
    FAULT,
    OVER,
    WIN
};

// 游戏难度
enum class GameLevel {
    BASIC,
    MEDIUM,
    HARD
};

// 游戏默认参数
constexpr int kRow = 15;
constexpr int kCol = 20;
constexpr int kMineCount = 50;
constexpr int kTime = 0;

class GameModel {
public:
    GameModel();
    virtual ~GameModel();

    void digMine(int m, int n);             // 挖雷，m是行，n是列
    void markMine(int m, int n);            // 标记雷
    void createGame(int row = kRow, int col = kCol, int mineCount = kMineCount, GameLevel level = GameLevel::MEDIUM); // 初始化游戏
    void restartGame();                     // 按当前参数重新开始游戏
    void checkGame();                       // 检查游戏输赢

public:
    std::vector<std::vector<MineBlock>> gameMap; // 游戏地图
    int mRow;            // 地图行数
    int mCol;            // 地图列数
    int totalMineNumber; // 雷数
    int curMineNumber;   // 当前雷数（仅用于显示）
    int timerSeconds;    // 计时（秒）

    GameState gameState; // 当前游戏状态
    GameLevel gameLevel; // 当前游戏难度
};

#endif // GAMEMODEL_H
