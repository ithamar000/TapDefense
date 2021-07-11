package com.example.tapdefense;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import static com.example.tapdefense.GameView.screenX;
import static com.example.tapdefense.GameView.screenY;

public class SilverMonster extends Enemy {

    static Bitmap e1_run,e2_run,e3_run,e4_run,e5_run,e6_run,e7_run,e8_run,e9_run,e10_run;
    static Bitmap e1_hit,e2_hit,e3_hit,e4_hit,e5_hit,e6_hit,e7_hit,e8_hit,e9_hit,e10_hit;
    static Bitmap e1_die,e2_die,e3_die,e4_die,e5_die,e6_die,e7_die,e8_die,e9_die,e10_die;

    public SilverMonster(Resources res, boolean firstTime) {
        super(res);
        startHealth = 2;
        isDie = 2;
        hit=false;
        speed = 14;
        tapCounter =startHealth;
        width = (int) (screenX/5);
        height = (int) ((screenY/5)*1.3);
        if (firstTime)
            initAnimation(res);
        loadRes("run",res);
        y = -height;
    }

    @Override
    void loadRes(String mode, Resources res) {
        enemyCounter =1;
        switch (mode){
            case ("run"):
                e1 = Bitmap.createScaledBitmap(e1_run, width, height, false);
                e2 = Bitmap.createScaledBitmap(e2_run, width, height, false);
                e3 = Bitmap.createScaledBitmap(e3_run, width, height, false);
                e4 = Bitmap.createScaledBitmap(e4_run, width, height, false);
                e5 = Bitmap.createScaledBitmap(e5_run, width, height, false);
                e6 = Bitmap.createScaledBitmap(e6_run, width, height, false);
                e7 = Bitmap.createScaledBitmap(e7_run, width, height, false);
                e8 = Bitmap.createScaledBitmap(e8_run, width, height, false);
                e9 = Bitmap.createScaledBitmap(e9_run, width, height, false);
                e10 = Bitmap.createScaledBitmap(e10_run, width, height, false);

                break;
            case("hit"):
                e1 = Bitmap.createScaledBitmap(e1_hit, width, height, false);
                e2 = Bitmap.createScaledBitmap(e2_hit, width, height, false);
                e3 = Bitmap.createScaledBitmap(e3_hit, width, height, false);
                e4 = Bitmap.createScaledBitmap(e4_hit, width, height, false);
                e5 = Bitmap.createScaledBitmap(e5_hit, width, height, false);
                e6 = Bitmap.createScaledBitmap(e6_hit, width, height, false);
                e7 = Bitmap.createScaledBitmap(e7_hit, width, height, false);
                e8 = Bitmap.createScaledBitmap(e8_hit, width, height, false);
                e9 = Bitmap.createScaledBitmap(e9_hit, width, height, false);
                e10 = Bitmap.createScaledBitmap(e10_hit, width, height, false);

                break;

            case("die"):
                e1 = Bitmap.createScaledBitmap(e1_die, width, height, false);
                e2 = Bitmap.createScaledBitmap(e2_die, width, height, false);
                e3 = Bitmap.createScaledBitmap(e3_die, width, height, false);
                e4 = Bitmap.createScaledBitmap(e4_die, width, height, false);
                e5 = Bitmap.createScaledBitmap(e5_die, width, height, false);
                e6 = Bitmap.createScaledBitmap(e6_die, width, height, false);
                e7 = Bitmap.createScaledBitmap(e7_die, width, height, false);
                e8 = Bitmap.createScaledBitmap(e8_die, width, height, false);
                e9 = Bitmap.createScaledBitmap(e9_die, width, height, false);
                e10 = Bitmap.createScaledBitmap(e10_die, width, height, false);

                break;
        }
    }
    void initAnimation(Resources res){
        e1_run = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_run_000);
        e2_run = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_run_002);
        e3_run = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_run_004);
        e4_run = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_run_006);
        e5_run = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_run_008);
        e6_run = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_run_010);
        e7_run = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_run_012);
        e8_run = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_run_014);
        e9_run = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_run_016);
        e10_run = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_run_018);

        e1_hit = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_attack_000);
        e2_hit = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_attack_002);
        e3_hit = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_attack_004);
        e4_hit = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_attack_006);
        e5_hit = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_attack_008);
        e6_hit = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_attack_010);
        e7_hit = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_attack_012);
        e8_hit = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_attack_014);
        e9_hit = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_attack_016);
        e10_hit = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_attack_018);

        e1_die= BitmapFactory.decodeResource(res,R.drawable.s_enemies_1_die_000);
        e2_die = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_die_002);
        e3_die = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_die_004);
        e4_die = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_die_006);
        e5_die = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_die_008);
        e6_die = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_die_010);
        e7_die = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_die_012);
        e8_die = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_die_014);
        e9_die = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_die_016);
        e10_die = BitmapFactory.decodeResource(res, R.drawable.s_enemies_1_die_018);

    }
}
