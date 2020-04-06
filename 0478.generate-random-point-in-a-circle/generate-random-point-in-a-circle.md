# 478. 在圆内随机生成点

## 题目描述

给定圆的半径和圆心的 x、y 坐标，写一个在圆中产生均匀随机点的函数 randPoint 。

说明:

1. 输入值和输出值都将是浮点数。
2. 圆的半径和圆心的 x、y 坐标将作为参数传递给类的构造函数。
3. 圆周上的点也认为是在圆中。
4. randPoint 返回一个包含随机点的x坐标和y坐标的大小为2的数组。

示例 1：
```java
输入: 
["Solution","randPoint","randPoint","randPoint"]
[[1,0,0],[],[],[]]
输出: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]
```
示例 2：
```java
输入: 
["Solution","randPoint","randPoint","randPoint"]
[[10,5,-7.5],[],[],[]]
输出: [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]
```
输入语法说明：

输入是两个列表：调用成员函数名和调用的参数。Solution 的构造函数有三个参数，圆的半径、圆心的 x 坐标、圆心的 y 坐标。randPoint 没有参数。输入参数是一个列表，即使参数为空，也会输入一个 [] 空列表。

## 解题思路

使用拒绝采样的方法。

使用一个边长为 2R 的正方形覆盖住圆 C，并在正方形内随机生成点，若该点落在圆内，我们就返回这个点，否则我们拒绝这个点，重新生成直到新的随机点落在圆内。

![](https://pic.leetcode-cn.com/Figures/883/squareCircleOverlay.png)

## 解题代码

### Java

```java
class Solution {
    private double radius;
    private double x_center;
    private double y_center;

    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;
    }
    
    public double[] randPoint() {
        // 正方形左下角坐标
        double x0 = x_center - radius;
        double y0 = y_center - radius;
        double x, y, distance;
        do {
            x = x0 + Math.random() * 2 * radius;
            y = y0 + Math.random() * 2 * radius;
            distance = Math.pow(x - x_center, 2) + Math.pow(y - y_center, 2);
        }while(distance > radius * radius);
        return new double[]{x, y};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */
```

