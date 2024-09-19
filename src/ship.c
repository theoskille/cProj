

// // function that takes a 2D array of TileType and an input file. The file represents the ship layout where each character represents a tile type. The function should read the file and populate the 2D array with the corresponding tile types. The function should return 0 if successful and -1 if there was an error.
// int loadShipLayout(TileType** grid, const char* filename) {
//     FILE* file = fopen(filename, "r");
//     if (!file) {
//         return -1;
//     }

//     int x = 0;
//     int y = 0;
//     char c;
//     while ((c = fgetc(file)) != EOF) {
//         if (c == '\n') {
//             y++;
//             x = 0;
//         } else {
//             if (x >= GRID_WIDTH || y >= GRID_HEIGHT) {
//                 fclose(file);
//                 return -1;
//             }
//             switch (c) {
//                 case '0':
//                     grid[y][x] = EMPTY;
//                     break;
//                 case '1':
//                     grid[y][x] = WALL;
//                     break;
//                 case '2':
//                     grid[y][x] = DOOR;
//                     break;
//                 default:
//                     fclose(file);
//                     return -1;
//             }
//             x++;
//         }
//     }

//     fclose(file);
//     return 0;
// }