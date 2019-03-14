package com.xiaosongsz.GPlatform;

import org.json.JSONObject;

public interface IGPlatform {
    JSONObject receiveMessage(JSONObject message);
}
