class Robot {
public:
    int x = 0, y = 0;
    int d = 0;
    int w, h, cir;
    vector<string> dir{"East","North","West","South"};

    Robot(int width, int height) {
        w = width - 1;
        h = height - 1;
        cir = 2 * (w + h);   // FIXED
    }

    void step(int num) {
        num = num % cir;

        if (num == 0 && x == 0 && y == 0) {
            d = 3; // South
            return;
        }

        while (num > 0) {
            if (d == 0) {
                if (x + num > w) {
                    num -= (w - x);
                    x = w;
                    d = 1;
                } else {
                    x += num;
                    num = 0;
                }
            }
            else if (d == 1) {
                if (y + num > h) {
                    num -= (h - y);
                    y = h;
                    d = 2;
                } else {
                    y += num;
                    num = 0;
                }
            }
            else if (d == 2) {
                if (x - num < 0) {
                    num -= x;
                    x = 0;
                    d = 3;
                } else {
                    x -= num;
                    num = 0;
                }
            }
            else {
                if (y - num < 0) {
                    num -= y;
                    y = 0;
                    d = 0;
                } else {
                    y -= num;
                    num = 0;
                }
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return dir[d];
    }
};