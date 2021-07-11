package com.example.tapdefense;

import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;
import android.graphics.PorterDuff;
import android.graphics.Rect;
import android.media.MediaPlayer;
import android.view.MotionEvent;
import android.view.SurfaceView;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class GameView extends SurfaceView implements Runnable {
    private Thread thread;
    private boolean isPlaying;
    boolean SOUND_STATE;
    static MediaPlayer tap_sound;
    int health = 10;
    static int screenX, screenY;
    static int time;
    private Paint paint;
    double counter=0;
    private List<Enemy> enemies;
    private Random random;
    float speedFactor = 1f;
    int numOfEnemies=4;
    boolean finishFlag;
    static float screenRatioX, screenRatioY;
    private Background background1, background2;
    private Bitmap castle;
    private Rect finishLine;
    int enemyOnScreen;
    int maxEnemyOnScreen ;
    int typeBound=5;
    int bombLimt = 15;
    Bitmap pic,explosion;
    int score=0;
    int[] previous_scores = new int[5];
    SharedPreferences sp;



    public GameView(Context context, int screenX, int screenY,String diff) {
        super(context);
        maxEnemyOnScreen = numOfEnemies;
        enemies = new ArrayList<>();
        this.screenX = screenX;
        this.screenY = screenY;
        screenRatioX = 1920f / screenX;
        screenRatioY = 1080f / screenY;
        tap_sound = MediaPlayer.create(context,R.raw.click1);
        background1 = new Background(screenX,screenY, getResources());
        background2 = new Background(screenX,screenY, getResources());
        finishFlag = false;
        castle = BitmapFactory.decodeResource(getResources(),R.drawable.castle_trans);
        castle = Bitmap.createScaledBitmap(castle,screenX/6,screenY,false);
        finishLine = new Rect(screenX - 40, 0, screenX, screenY);
        random = new Random();
        Random rnd = new Random();
        background2.x = screenX;
        paint = new Paint();
        pic = BitmapFactory.decodeResource(getResources(),R.drawable.bar);
        pic = Bitmap.createScaledBitmap(pic,600,220,false);
        explosion = BitmapFactory.decodeResource(getResources(),R.drawable.explosion);
        explosion = Bitmap.createScaledBitmap(explosion,screenX/11,screenX/11,false);
        sp = context.getSharedPreferences("details",context.MODE_PRIVATE);
        previous_scores[0] = sp.getInt("1st_score",0);
        previous_scores[1]=sp.getInt("2st_score",0);
        previous_scores[2]=sp.getInt("3st_score",0);
        previous_scores[3]=sp.getInt("4st_score",0);
        previous_scores[4]=sp.getInt("5st_score",0);

        switch (diff){
            case ("easy"):
                speedFactor = 0.8f;
                maxEnemyOnScreen = 6;
                break;
            case ("normal"):
                speedFactor = 1.0f;
                maxEnemyOnScreen = 8;
                break;
            case ("hard"):
                speedFactor = 1.1f;
                maxEnemyOnScreen = 12;
                break;
        }
        Enemy enemy_init = new GreenMonster (getResources(),true);
        enemy_init = new SilverMonster (getResources(),true);
        enemy_init = new BlackMonster (getResources(),true);
        enemyOnScreen=numOfEnemies;
        
        for (int i = 0; i< numOfEnemies; i++){

            int typeEnemy = rnd.nextInt(typeBound);
            Enemy enemy;

            if(typeEnemy<=7) {
                enemy = new GreenMonster(getResources(),true);
            }
            else{
                enemy = new SilverMonster (getResources(),true);
                }
            enemy.x = 0 - enemy.width - rnd.nextInt(1000);
            enemy.y = (screenY / 4) + random.nextInt(screenY / 2);

            enemies.add(enemy);

        }



    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        final int action = event.getAction();
        switch (action & MotionEvent.ACTION_MASK) {
            case MotionEvent.ACTION_DOWN:
                final float x = event.getX();
                final float y = event.getY();
                Point p = new Point((int)(x),(int)(y));
                for (Enemy enemy : enemies)
                    // (x > enemy.x && x < enemy.x + enemy.width && y > enemy.y && y < enemy.y + enemy.height)
                    if(pointInRect(p,new Rect(enemy.x,enemy.y,enemy.x+enemy.width,enemy.y+enemy.height)))
                    {
                        //isPlaying = false;
                        if(SOUND_STATE)
                            tap_sound.start();
                        enemy.isDie--;
                        if (enemy.isDie  == 0) {
                            enemy.isDie = -1;
                        }
                        if (enemy.tapCounter>0)
                            enemy.tapCounter--;
                            //enemy.speed = 10;
                        //}
                        break; // to handle overlapping enemies
                    }
                if (score>bombLimt && pointInRect(p,new Rect(screenX/10,(screenY-screenY/4),screenX/10+explosion.getWidth(),(screenY-screenY/4)+explosion.getHeight()))) {
                    if (enemyOnScreen>0) {
                        enemies.clear();
                        enemyOnScreen = 0;
                    }
                    score -= bombLimt;
                }
                break;

        }
       return super.onTouchEvent(event);
    }

    @Override
    public void run() {

        while(isPlaying) {
            counter+=0.2;
            update();
            draw();
            sleep();
        }

    }

    private void update(){
        List<Enemy> trash = new ArrayList<>();
        timeTicking();
        if (enemyOnScreen<maxEnemyOnScreen)
            enemies.add(createEnemy());

        for (Enemy enemy : enemies){

                enemy.x += (int)(enemy.speed * speedFactor);

            if (enemy.isDie  == -1) {
                enemy.isDie = -2;
                enemy.loadRes("die", getResources());
            }else if(enemy.isDie <=-2 && enemy.enemyCounter == 10) {
                trash.add(enemy);
                enemyOnScreen--;
                score +=enemy.startHealth;

            }
            if (enemy.hit && enemy.enemyCounter==10)
                health -=enemy.startHealth;

                if (Rect.intersects(enemy.getCollisionShape(), finishLine)) {
                    finishFlag = false;
                    enemy.speed = 0;
                    if (!enemy.hit) {
                        enemy.loadRes("hit", getResources());
                        enemy.hit = true;
                    }
                }

        }
       for (Enemy enemy : trash){
            enemies.remove(enemy);
        }
       if (health <= 0) {
           health = 0;
           isPlaying = false;
       }
    }

    private void draw (){
        if(getHolder().getSurface().isValid()){
            Canvas canvas = getHolder().lockCanvas();
            canvas.drawBitmap(background1.background, background1.x, background1.y, paint);
            canvas.drawBitmap(castle,screenX-castle.getWidth(),0,paint);
            if (finishFlag){
                isPlaying = false;
            }
            if (score > bombLimt)
                canvas.drawBitmap(explosion,screenX/10,(screenY-screenY/4),paint);
            //else
                //canvas.drawBitmap(explosion,screenX/10,(screenY-screenY/6),paint);
            paint.setColor(Color.WHITE);
            paint.setTextSize(100);
            score+=time/100;
            canvas.drawBitmap(pic,screenX/5,screenY/8,paint);
            canvas.drawText("Score: "+score,screenX/2,200,paint);
            canvas.drawText("highscore:"+previous_scores[4],screenX/2+400,200,paint);
            canvas.drawText("Life: "+health,screenX/5,screenY/8,paint);
            for (Enemy enemy: enemies){
                canvas.drawBitmap(enemy.getEnemy(), enemy.x, enemy.y, paint);
                paint.setTextSize(50);
                canvas.drawText(enemy.tapCounter+"",enemy.x+150,enemy.y+20,paint);
            }
            paint.setTextSize(100);
            if (!isPlaying)
                gameOver(canvas);
            getHolder().unlockCanvasAndPost(canvas);
        }
    }

    private void sleep (){
        try {
            Thread.sleep(10);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

    public void resume() {
        isPlaying = true;
        thread = new Thread(this);
        thread.start();
    }

    public void pause(){
        try {
            thread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        checkHighScore();


    }


    Enemy createEnemy(){
        Random rnd = new Random();
        int typeEnemy = rnd.nextInt(typeBound);
        Enemy enemy;
        if(typeEnemy<=10) {
            enemy = new GreenMonster(getResources(),false);
            enemy.x = 0 - enemy.width - rnd.nextInt(1000);
            enemy.y = (screenY / 4) + random.nextInt(screenY / 2);
        }
        else if(typeEnemy<=15){
            enemy = new SilverMonster (getResources(),false);
            enemy.x = 0 - enemy.width - rnd.nextInt(1000);
            enemy.y = (screenY / 4) + random.nextInt(screenY / 2);
        }else{
            enemy = new BlackMonster (getResources(),false);
            enemy.x = 0 - enemy.width - rnd.nextInt(1000);
            enemy.y = (screenY / 4) + random.nextInt(screenY / 2);
        }
        enemyOnScreen++;
        return enemy;
    }

    void timeTicking(){
        time = (int)(counter/7);
        if (time>5)
            typeBound = time;
        if (speedFactor < 1.5f)
            speedFactor = (float)(speedFactor*1.0005);

    }


    boolean pointInRect(Point p, Rect r){

        if (p.x > r.left && p.x < r.right && p.y > r.top && p.y < r.bottom)
            return true;
        return false;
    }

    void checkHighScore(){
        Canvas canvas_highscore = getHolder().lockCanvas();
        if (score > previous_scores[0])
        {
            previous_scores[0] = score;
            paint.setColor(Color.WHITE);
            paint.setTextSize(200);
            canvas_highscore.drawText("New High scrore", 100 ,100,paint);
        }
        Arrays.sort(previous_scores);

        SharedPreferences.Editor editor = sp.edit();
        editor.putInt("1st_score",previous_scores[0]);
        editor.putInt("2st_score",previous_scores[1]);
        editor.putInt("3st_score",previous_scores[2]);
        editor.putInt("4st_score",previous_scores[3]);
        editor.putInt("5st_score",previous_scores[4]);
        editor.commit();
    }
    void gameOver(Canvas canvas){

        canvas.drawColor(Color.WHITE, PorterDuff.Mode.CLEAR);

        canvas.drawBitmap(background1.background,background1.x,background1.y,paint);
        paint.setTextSize(200);
        canvas.drawText("GAME OVER!",screenX/2-(screenX/10),screenY/2,paint);
        paint.setTextSize(100);
        canvas.drawText("Your score is: "+score,screenX/2,screenY/2+200,paint);



    }




}
