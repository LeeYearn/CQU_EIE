package com.example.calculator;

import android.animation.ObjectAnimator;
import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewTreeObserver;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import java.util.Stack;

public class MainActivity extends AppCompatActivity {
    private TextView resultInput;
    private TextView resultAnswer;
    private String currentInput = "";
    private double total = 0;
    private boolean pointFlag = true;
    private int bracketCount = 0;
    private boolean isTextOverflow = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.basic);

        final Button buttonBack = findViewById(R.id.buttonBack);
        buttonBack.getViewTreeObserver().addOnGlobalLayoutListener(new ViewTreeObserver.OnGlobalLayoutListener() {
            @Override
            public void onGlobalLayout() {
                buttonBack.getViewTreeObserver().removeOnGlobalLayoutListener(this);
                int newPaddingStart = (buttonBack.getWidth() / 2) - 36;
                buttonBack.setPaddingRelative(newPaddingStart, buttonBack.getPaddingTop(), buttonBack.getPaddingEnd(), buttonBack.getPaddingBottom());
            }
        });

        resultInput = findViewById(R.id.resultInput);
        resultAnswer = findViewById(R.id.resultAnswer);

        setupButtons();
    }

    @SuppressLint("ClickableViewAccessibility")
    private void setupButtons() {
        int[] buttonIds = {
                R.id.buttonAC,  R.id.buttonBack,
                R.id.buttonLeft_bracket, R.id.buttonRight_bracket, R.id.buttonPercent,   R.id.buttonDiv,
                R.id.buttonN7,  R.id.buttonN8,      R.id.buttonN9,      R.id.buttonMulti,
                R.id.buttonN4,  R.id.buttonN5,      R.id.buttonN6,      R.id.buttonSub,
                R.id.buttonN1,  R.id.buttonN2,      R.id.buttonN3,      R.id.buttonAdd,
                /*R.id.buttonE,*/   R.id.buttonN0,      R.id.buttonPoint,   R.id.buttonEqual,
        };

        for (int id : buttonIds) {
            Button button = findViewById(id);
            button.setOnTouchListener((v, event) -> {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // 按下时缩放按钮
                        v.setScaleX(0.85f);
                        v.setScaleY(0.85f);
                        break;
                    case MotionEvent.ACTION_UP:
                    case MotionEvent.ACTION_CANCEL:
                        // 抬起时恢复按钮大小
                        v.setScaleX(1f);
                        v.setScaleY(1f);
                        // 确保在抬起时也触发点击事件
                        if (event.getAction() == MotionEvent.ACTION_UP)v.performClick();
                        break;
                }
                return true; // 返回true表示事件已被消费
            });
            button.setOnClickListener(new ButtonClickListener());
        }
    }

    private class ButtonClickListener implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            if (v.getId() == R.id.buttonAC) {
                clear();
                System.out.println("按下了AC");
                encapsulation(0);
            }else if (v.getId() == R.id.buttonEqual) {
                System.out.println("按下了=");
                currentInput = "";
                total = 0;
                encapsulation(1);
            } else if(v.getId() == R.id.buttonBack){
                System.out.println("按下了Back");
                if(!currentInput.isEmpty()) back();
                checkTextSize();
                //calculate();
                v.getId();
            }else {
                displayInput(((Button) v).getText().toString());
                if(isInit(v)){
                    if(total == 0&&!isTextOverflow)encapsulation(0);
                }
                //calculate();
            }
        }
    }

    private boolean isInit(@NonNull View v){
        return v.getId() == R.id.buttonLeft_bracket||v.getId() == R.id.buttonRight_bracket || v.getId() == R.id.buttonN1 || v.getId() == R.id.buttonN2 || v.getId() == R.id.buttonN3 || v.getId() == R.id.buttonN4 || v.getId() == R.id.buttonN5 || v.getId() == R.id.buttonN6 || v.getId() == R.id.buttonN7 || v.getId() == R.id.buttonN8 || v.getId() == R.id.buttonN9 || v.getId() == R.id.buttonN0;
    }

    private void displayInput(String input) {
        if(currentInput.isEmpty() && isOperator(input)){
            System.out.println("没成功输入");
            return;
        }
        System.out.println("input"+input);
        if (isOperator(input)) {
            pointFlag = true;
            if(isOperator(String.valueOf(currentInput.charAt(currentInput.length() - 1)))) {
                currentInput = currentInput.substring(0, currentInput.length() - 1);
            }else if(String.valueOf(currentInput.charAt(currentInput.length() - 1)).equals(".")){
                currentInput += "0";
            }
        }else if(input.equals(".")){
            if(pointFlag){
                pointFlag = false;
                if(currentInput.isEmpty()){
                    currentInput = "0";
                }else if(String.valueOf(currentInput.charAt(currentInput.length() - 1)).equals(".")){
                    currentInput = currentInput.substring(0, currentInput.length() - 1);
                }else if(isOperator(String.valueOf(currentInput.charAt(currentInput.length() - 1)))){
                    currentInput += "0";
                }
            }else return;
        }else if(input.equals("(")){
            bracketCount++;
        }else if(input.equals(")")){
            if(bracketCount == 0)return;
            bracketCount--;
        }else if(input.equals("e"))return;
        System.out.println("bracketCount"+bracketCount);
        currentInput += input;
        resultInput.setText(currentInput);
        checkTextSize();


    }

    private void checkTextSize() {
        // 获取当前视图宽度
        int width = resultInput.getMeasuredWidth();
        // 获取当前文本宽度，加上一个字符作为预判
        float textWidth = resultInput.getPaint().measureText(currentInput + "8");
        float targetSize = 80.0f; // 默认目标大小
        float minSize = 40.0f; // 最小大小

        if (textWidth > width) {
            // 如果文本超出宽度，逐步减小字体大小
            float newSize = resultInput.getTextSize() / getResources().getDisplayMetrics().scaledDensity; // 当前大小

            while (textWidth > width && newSize > minSize) {
                newSize -= 2; // 每次减少2sp
                resultInput.setTextSize(newSize);
                textWidth = resultInput.getPaint().measureText(currentInput + "0"); // 重新测量，加入宽字符
            }
            isTextOverflow = true; // 设置标志为true
        } else if (isTextOverflow) {
            // 如果宽度在范围内并且之前超出，逐步恢复到目标大小
            float currentSize = resultInput.getTextSize() / getResources().getDisplayMetrics().scaledDensity; // 获取当前字体大小
            while (currentSize < targetSize) {
                currentSize += 2; // 每次增加2sp
                resultInput.setTextSize(currentSize);
                textWidth = resultInput.getPaint().measureText(currentInput+"00"); // 重新测量，加入宽字符
                // 检查是否超出宽度
                if (textWidth > width) {
                    break; // 如果超出，停止增加
                }
            }
            // 如果成功恢复到正常范围，则重置标志
            if (currentSize >= targetSize) {
                isTextOverflow = false; // 设置标志为false
            }
        }
    }


    private void back( ){
        currentInput = currentInput.substring(0, currentInput.length() - 1);
        if(currentInput.isEmpty()){
            clear();
            return;
        }
        resultInput.setText(currentInput);
    }

    private void encapsulation(int flag){
        if(flag == 1){
            animateTextSize(resultInput, 40, ContextCompat.getColor(MainActivity.this, R.color.text_color3)); // 修改字体大小和颜色
            animateTextSize(resultAnswer, 80, ContextCompat.getColor(MainActivity.this, R.color.text_color1)); // 修改字体大小和颜色
        }else if(flag == 0){
            animateTextSize(resultInput, 80, ContextCompat.getColor(MainActivity.this, R.color.text_color1)); // 修改字体大小和颜色
            animateTextSize(resultAnswer, 40, ContextCompat.getColor(MainActivity.this, R.color.text_color3)); // 修改字体大小和颜色
        }
    }

    // 新增一个方法来执行字体大小动画
    private void animateTextSize(@NonNull final TextView textView, final float targetSize, int color) {
        textView.setTextColor(color);
        float currentSize = textView.getTextSize() / getResources().getDisplayMetrics().scaledDensity; // 获取当前字体大小（以sp为单位）
        ObjectAnimator animator = ObjectAnimator.ofFloat(textView, "textSize", currentSize, targetSize);
        animator.setDuration(300); // 设置动画持续时
        animator.start(); // 启动动画
    }

    private boolean isOperator(@NonNull String input) {
        return input.equals("+") || input.equals("-") || input.equals("×") || input.equals("÷");
    }

    private void clear() {
        isTextOverflow = false;
        currentInput = "";
        total = 0;
        resultInput.setText("0");
        resultAnswer.setText("0");
    }
}