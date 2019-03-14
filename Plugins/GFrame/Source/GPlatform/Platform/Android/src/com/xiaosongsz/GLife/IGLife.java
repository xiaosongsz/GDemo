package com.xiaosongsz.GLife;

import android.content.Context;

public interface IGLife {
    void onCreate(Context context);

    void onDestroy(Context context);

    void onPause(Context context);

    void onResume(Context context);
}
