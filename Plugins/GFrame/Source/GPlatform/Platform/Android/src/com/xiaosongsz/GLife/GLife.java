package com.xiaosongsz.GLife;

import android.content.Context;
import com.xiaosongsz.GPlatform.GPlatform;

import java.util.ArrayList;

public class GLife extends ArrayList<IGLife> {
    private static final String TAG = "GLife";

    protected static GLife instance = null;
    public static GLife getInstance(){
        if (instance == null){
            instance = new GLife();
        }
        return instance;
    }

    private GLife(){
        GPlatform.getInstance();
    }

    public Context getContext() {
        return context;
    }

    protected Context context;

    public void onCreate(Context context){
        this.context = context;
        for (IGLife life : this) {
            life.onCreate(this.context);
        }
    }

    public void onDestroy(){
        for (IGLife life : this) {
            life.onDestroy(this.context);
        }
    }

    public void onPause(){
        for (IGLife life : this) {
            life.onPause(this.context);
        }
    }

    public void onResume(){
        for (IGLife life : this) {
            life.onResume(this.context);
        }
    }
}
