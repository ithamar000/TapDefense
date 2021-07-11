package com.example.tapdefense;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.Rect;

public class Enemy {

    public int speed;
    boolean hit;
    int isDie = 0; // 0 = false, 1 = true, 2 = true but already changed once
    int tapCounter;
    int x = 0 , y, width, height, enemyCounter = 1;
    Bitmap e1, e2, e3, e4,e5,e6, e7, e8, e9, e10;
    int startHealth;



    Enemy (Resources res) {}
    void loadRes(String mode,Resources res){ }

    Bitmap getEnemy (){
        switch (enemyCounter){
            case 1:
                enemyCounter++;
                return e1;
            case 2:
                enemyCounter++;
                return e2;
            case 3:
                enemyCounter++;
                return e3;
            case 4:
                enemyCounter++;
                return e4;
            case 5:
                enemyCounter++;
                return e5;
            case 6:
                enemyCounter++;
                return e6;
            case 7:
                enemyCounter++;
                return e7;
            case 8:
                enemyCounter++;
                return e8;
            case 9:
                enemyCounter++;
                return e9;
            default:
                enemyCounter = 1;
                return e10;
        }
    }

    Rect getCollisionShape (){
        return new Rect(x,y,x + width,y + height);
    }

    boolean isdied(){
        if (tapCounter==0)
            return true;
        else
            return false;

    }

}

