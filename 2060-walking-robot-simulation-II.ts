const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];

class Robot {
    width: number;
    height: number;
    dir: number;
    x: number;
    y: number;


    constructor(width: number, height: number) {
        this.width = width;
        this.height = height;
        this.dir = 0;
        this.x = 0;
        this.y = 0;
    }

    step(num: number): void {
        // 取模，不然会超时。先减一后加一，处理的情况是原点特殊情况
        num = (num - 1) % ((this.width - 1 + this.height - 1) * 2) + 1;
        for (let i = 0; i < num; i++) {
            let nextX = this.x + dx[this.dir];
            let nextY = this.y + dy[this.dir];
            if (nextX >= this.width || nextX <= -1 || nextY >= this.height || nextY <= -1) {
                //turn direction and recompute the nextX and nextY
                this.dir = (this.dir + 1) % 4;
                nextX = this.x + dx[this.dir];
                nextY = this.y + dy[this.dir];
            }
            this.x = nextX;
            this.y = nextY;
        }
        
    }

    getPos(): number[] {
        return [this.x, this.y];
    }

    getDir(): string {
        return ["East", "North", "West", "South"][this.dir];
    }
}

/**
 * Your Robot object will be instantiated and called as such:
 * var obj = new Robot(width, height)
 * obj.step(num)
 * var param_2 = obj.getPos()
 * var param_3 = obj.getDir()
 */