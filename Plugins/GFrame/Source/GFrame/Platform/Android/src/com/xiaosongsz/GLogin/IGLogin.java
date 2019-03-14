package com.xiaosongsz.GLogin;

import org.json.JSONObject;

public interface IGLogin {
    void login(JSONObject login);

    void logout(JSONObject logout);
}
