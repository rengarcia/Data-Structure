package com.example.proyecto;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void openMaps(View v){
        Intent i = new Intent(this, MapsActivity.class);
        startActivity(i);
    }

    public void openQR(View v){
        Intent i = new Intent(this, QRActivity.class);
        startActivity(i);
    }
}
