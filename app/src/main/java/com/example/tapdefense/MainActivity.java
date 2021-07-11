package com.example.tapdefense;

import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.graphics.PorterDuff;
import android.graphics.drawable.ColorDrawable;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.Window;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.ImageView;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    boolean MUSIC_STATE;
    boolean SOUND_STATE;
    SharedPreferences sp;

    static MediaPlayer musicPlayer;
    static MediaPlayer soundPlayer;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        sp = getSharedPreferences("details",MODE_PRIVATE);
        musicPlayer = MediaPlayer.create(getApplicationContext(),R.raw.bg_music);
        soundPlayer = MediaPlayer.create(getApplicationContext(),R.raw.click1);
        //menu Buttons animation
        Animation animDiffBtn = AnimationUtils.loadAnimation(this,R.anim.btn_menu_anim);
        Button btnDiffEasy = findViewById(R.id.btn_easyplay);
        Button btnDiffNormal = findViewById(R.id.btn_normalplay);
        Button btnDiffHard = findViewById(R.id.btn_hardplay);
        btnDiffEasy.startAnimation(animDiffBtn);
        btnDiffNormal.startAnimation(animDiffBtn);
        btnDiffHard.startAnimation(animDiffBtn);
        //logo animation
        Animation animLogo = AnimationUtils.loadAnimation(this,R.anim.logo_anim);
        Animation animLogoText = AnimationUtils.loadAnimation(this,R.anim.logo_anim_text);
        //animLogoText.setStartOffset(1000);
        ImageView imgLogo = findViewById(R.id.imgV_Logo);
        ImageView imgLogoText = findViewById(R.id.logo_text);
        imgLogo.startAnimation(animLogo);
        imgLogoText.startAnimation(animLogoText);
        imgLogoText.setVisibility(View.VISIBLE);
        //Bensound.com credit music
        final Button btnInfo = findViewById(R.id.btn_info);
        Button btnSettings = findViewById(R.id.btn_settings);
        Button btnScores = findViewById(R.id.btn_highScore);


        btnInfo.setOnTouchListener(new View.OnTouchListener() {

            @Override
            public boolean onTouch(View v, MotionEvent event) {

                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN: {
                        v.getBackground().setColorFilter(0XFFD8D8D8, PorterDuff.Mode.MULTIPLY);
                        v.invalidate();
                        break;
                    }
                    case MotionEvent.ACTION_UP: {
                        v.getBackground().clearColorFilter();
                        v.invalidate();
                        break;
                    }
                }
                return false;
            }



        });

        btnSettings.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN: {
                        v.getBackground().setColorFilter(0XFFD8D8D8, PorterDuff.Mode.MULTIPLY);
                        v.invalidate();
                        break;
                    }
                    case MotionEvent.ACTION_UP: {
                        v.getBackground().clearColorFilter();
                        v.invalidate();
                        break;
                    }
                }
                return false;
            }

        });
        btnScores.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN: {
                        v.getBackground().setColorFilter(0XFFD8D8D8, PorterDuff.Mode.MULTIPLY);
                        v.invalidate();
                        break;
                    }
                    case MotionEvent.ACTION_UP: {
                        v.getBackground().clearColorFilter();
                        v.invalidate();
                        break;
                    }
                }
                return false;
            }

        });

        btnInfo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (SOUND_STATE) soundPlayer.start();
                AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
                View dialogInfo = getLayoutInflater().inflate(R.layout.info_dialog,null);

                builder.setView(dialogInfo);
                AlertDialog dialog = builder.create();
                dialog.show();
                Window window = dialog.getWindow();
                window.setLayout(1500,800);
                window.setBackgroundDrawable(new ColorDrawable(Color.TRANSPARENT));
            }
        });

        btnScores.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (SOUND_STATE) soundPlayer.start();
            }
        });

        btnSettings.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {

               AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
               View dialogSettings = getLayoutInflater().inflate(R.layout.settings_dialog,null);
               final ImageView iv_music = dialogSettings.findViewById(R.id.iV_music);
               final ImageView iv_sound = dialogSettings.findViewById(R.id.iV_sound);

               if (SOUND_STATE) soundPlayer.start();
               builder.setView(dialogSettings);
               final AlertDialog dialog = builder.create();
               dialog.show();
               Window window = dialog.getWindow();
               window.setLayout(1000, 700);
               dialog.getWindow().setBackgroundDrawable(new ColorDrawable(Color.TRANSPARENT));

                if(MUSIC_STATE)
                    iv_music.setImageResource(R.drawable.music);
                else
                    iv_music.setImageResource(R.drawable.music_off);

                if(SOUND_STATE)
                    iv_sound.setImageResource(R.drawable.sound);
                else
                    iv_sound.setImageResource(R.drawable.sound_off);
               iv_music.setOnClickListener(new View.OnClickListener() {
                   @Override
                   public void onClick(View v) {
                       if (SOUND_STATE) soundPlayer.start();
                       if(musicPlayer.isPlaying()==true) {
                           musicPlayer.pause();
                           MUSIC_STATE = false;
                           iv_music.setImageResource(R.drawable.music_off);
                       }
                       else {
                           musicPlayer.start();
                           MUSIC_STATE = true;
                           iv_music.setImageResource(R.drawable.music);
                       }
                   }
               });

               iv_sound.setOnClickListener(new View.OnClickListener() {
                   @Override
                   public void onClick(View v) {
                       if (SOUND_STATE) soundPlayer.start();
                       if (SOUND_STATE) {
                           SOUND_STATE = false;
                           iv_sound.setImageResource(R.drawable.sound_off);

                       } else {
                           iv_sound.setImageResource(R.drawable.sound);
                           SOUND_STATE =  true;
                       }
                   }
               });

            }
        });
        btnDiffEasy.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent gameIntent = new Intent(MainActivity.this,GameActivity.class);
                gameIntent.putExtra("diff","easy");
                gameIntent.putExtra("sound_state",SOUND_STATE);
                gameIntent.putExtra("music_state",MUSIC_STATE);
                startActivity(gameIntent);

            }
        });
        btnDiffNormal.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent gameIntent = new Intent(MainActivity.this,GameActivity.class);
                gameIntent.putExtra("diff","normal");
                gameIntent.putExtra("sound_state",SOUND_STATE);
                gameIntent.putExtra("music_state",MUSIC_STATE);
                startActivity(gameIntent);
            }
        });

        btnDiffHard.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent gameIntent = new Intent(MainActivity.this,GameActivity.class);
                gameIntent.putExtra("diff","hard");
                gameIntent.putExtra("sound_state",SOUND_STATE);
                gameIntent.putExtra("music_state",MUSIC_STATE);
                startActivity(gameIntent);
            }
        });

    }

    /*this function handle fullscreen immersive mode
     * hide navigation bar and replace it to sticky bar*/
    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        if (hasFocus) {
            //hideSystemUI();
        }
        hideSystemUI();

    }
    private void hideSystemUI() {
        // Enables regular immersive mode.
        // For "lean back" mode, remove SYSTEM_UI_FLAG_IMMERSIVE.
        // Or for "sticky immersive," replace it with SYSTEM_UI_FLAG_IMMERSIVE_STICKY
        View decorView = getWindow().getDecorView();
        decorView.setSystemUiVisibility(
                View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
                        // Set the content to appear under the system bars so that the
                        // content doesn't resize when the system bars hide and show.
                        | View.SYSTEM_UI_FLAG_LAYOUT_STABLE
                        | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                        | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
                        // Hide the nav bar and status bar
                        | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                        | View.SYSTEM_UI_FLAG_FULLSCREEN);
    }



    @Override
    protected void onResume() {
        super.onResume();
        MUSIC_STATE = sp.getBoolean("music_state",true);
        SOUND_STATE = sp.getBoolean("sound_state",true);
        if (MUSIC_STATE)
            musicPlayer.start();


    }

    @Override
    protected void onPause() {
        super.onPause();
        if(MUSIC_STATE)
            musicPlayer.pause();


        SharedPreferences.Editor editor = sp.edit();
        editor.putBoolean("music_state",MUSIC_STATE);
        editor.putBoolean("sound_state",SOUND_STATE);
        editor.commit();
    }
}

