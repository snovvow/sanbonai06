package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int result = 0;
        String time = br.readLine();
        Long startTime = Long.parseLong(time.substring(0, 2)) * 60 + Long.parseLong(time.substring(3, 5));
        Long finishTime = Long.parseLong(time.substring(6, 8)) * 60 + Long.parseLong(time.substring(9, 11));
        Long quitTime = Long.parseLong(time.substring(12, 14)) * 60 + Long.parseLong(time.substring(15, 17));
        String input = null;
        HashMap<String, Long> map = new HashMap<>();
        while((input = br.readLine()) != null) {
            if (input.length() > 0) {
                String[] ary = input.split(" ");
                String[] split = ary[0].split(":");
                Long hour = Long.valueOf(split[0]);
                Long minutes = Long.valueOf(split[1]);
                String name = ary[1];
                Long totalTime = hour * 60 + minutes;
                if (totalTime <= startTime) {
                    map.put(name, 0L);
                } else if (totalTime >= finishTime && totalTime <= quitTime) {
                    if (map.containsKey(name) && map.get(name) != 1L) {
                        map.replace(name, 1L);
                        result = result + 1;
                    }
                }
            } else break;
        }
        System.out.println(result);
    }
}
