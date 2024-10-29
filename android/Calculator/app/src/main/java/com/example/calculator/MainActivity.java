package com.example.calculator;

import android.animation.ObjectAnimator;
import android.os.Bundle;
import android.view.View;
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
    private double pointFlag = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.basic);
        resultInput = findViewById(R.id.resultInput);
        resultAnswer = findViewById(R.id.resultAnswer);

        setupButtons();
    }

    private void setupButtons() {
        int[] buttonIds = {
                R.id.buttonAC,  R.id.buttonBack,    R.id.buttonRoots,   R.id.buttonDiv,
                R.id.buttonN7,  R.id.buttonN8,      R.id.buttonN9,      R.id.buttonMulti,
                R.id.buttonN4,  R.id.buttonN5,      R.id.buttonN6,      R.id.buttonSub,
                R.id.buttonN1,  R.id.buttonN2,      R.id.buttonN3,      R.id.buttonAdd,
                R.id.buttonE,   R.id.buttonN0,      R.id.buttonPoint,   R.id.buttonEqual,
        };

        for (int id : buttonIds) {
            Button button = findViewById(id);
            button.setOnClickListener(new ButtonClickListener());
        }
    }

    private class ButtonClickListener implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            if (v.getId() == R.id.buttonAC) {
                clear();
                System.out.println("按下了AC");
                animateTextSize(resultInput, 80, ContextCompat.getColor(MainActivity.this, R.color.text_color1)); // 修改字体大小和颜色
                animateTextSize(resultAnswer, 40, ContextCompat.getColor(MainActivity.this, R.color.text_color3)); // 修改字体大小和颜色
            }else if (v.getId() == R.id.buttonEqual) {
                System.out.println("按下了=");
                currentInput = "";
                total = 0;
                animateTextSize(resultAnswer, 80, ContextCompat.getColor(MainActivity.this, R.color.text_color1));
                animateTextSize(resultInput, 40,ContextCompat.getColor(MainActivity.this, R.color.text_color3));
            } else if(v.getId() == R.id.buttonBack){
                System.out.println("按下了Back");
                if(!currentInput.isEmpty()){
                    back();
                    calculate();
                }
                v.getId();
            }else {
                displayInput(((Button) v).getText().toString());
                if(isNumber(v)){
                    if(total == 0){
                        animateTextSize(resultInput, 80, ContextCompat.getColor(MainActivity.this, R.color.text_color1)); // 修改字体大小和颜色
                        animateTextSize(resultAnswer, 40, ContextCompat.getColor(MainActivity.this, R.color.text_color3)); // 修改字体大小和颜色
                    }
                    calculate();
                }
            }
        }
    }

    // 新增一个方法来执行字体大小动画
    private void animateTextSize(@NonNull final TextView textView, final float targetSize, int color) {
        textView.setTextColor(color);
        float currentSize = textView.getTextSize() / getResources().getDisplayMetrics().scaledDensity; // 获取当前字体大小（以sp为单位）
        ObjectAnimator animator = ObjectAnimator.ofFloat(textView, "textSize", currentSize, targetSize);
        animator.setDuration(300); // 设置动画持续时
        animator.start(); // 启动动画}
    }

    private boolean isNumber(@NonNull View v){
        return v.getId() == R.id.buttonN1 || v.getId() == R.id.buttonN2 || v.getId() == R.id.buttonN3 || v.getId() == R.id.buttonN4 || v.getId() == R.id.buttonN5 || v.getId() == R.id.buttonN6 || v.getId() == R.id.buttonN7 || v.getId() == R.id.buttonN8 || v.getId() == R.id.buttonN9 || v.getId() == R.id.buttonN0;
    }

    private void calculate() {
        if (currentInput.isEmpty()) {
            return;
        }

        // 检查最后一个字符是否为数字，如果不是，则修剪掉
        if (!Character.isDigit(currentInput.charAt(currentInput.length() - 1))) {
            currentInput = currentInput.substring(0, currentInput.length() - 1);
        }

        // 将 "e" 替换为自然常数 Math.E
        String modifiedInput = currentInput.replace("e", String.valueOf(Math.E));
        Stack<Double> numStack = new Stack<>(); // 操作数栈
        Stack<Character> sigStack = new Stack<>(); // 操作符栈

        String[] parts = modifiedInput.split("(?<=[-+÷×])|(?=[-+÷×])");

        for (String part : parts) {
            // 如果是数字，则入栈
            if (!part.equals("+") && !part.equals("-") && !part.equals("×") && !part.equals("÷")) {
                numStack.push(Double.parseDouble(part));
            } else {
                // 处理运算符
                while (!sigStack.isEmpty() && getLevel(sigStack.peek()) >= getLevel(part.charAt(0))) {
                    calculateTop(numStack, sigStack);
                }
                sigStack.push(part.charAt(0));
            }
        }

        // 处理剩余的运算符
        while (!sigStack.isEmpty()) {
            calculateTop(numStack, sigStack);
        }

        double total = numStack.pop();
        String str = "=" + (total == (int) total ? Integer.toString((int)total) : Double.toString(total));
        resultAnswer.setText(str);
        System.out.println(total);
    }

    // 获取运算符优先级
    private int getLevel(char operator) {
        switch (operator) {
            case '^': return 3;
            case '×': case '÷': return 2;
            case '+': case '-': return 1;
            default: return 0;
        }
    }

    // 执行运算
    private void calculateTop(Stack<Double> numStack, Stack<Character> sigStack) {
        double b = numStack.pop();
        double a = numStack.pop();
        char operator = sigStack.pop();

        switch (operator) {
            case '+':
                numStack.push(a + b);
                break;
            case '-':
                numStack.push(a - b);
                break;
            case '×':
                numStack.push(a * b);
                break;
            case '÷':
                numStack.push(a / b);
                break;
            case '^':
                numStack.push(Math.pow(a, b));
                break;
        }
    }



    private void displayInput(String input) {
        if(currentInput.isEmpty() && isOperator(input) || currentInput.length() == 17){
            return;
        }

        if (isOperator(input)) {
            pointFlag = 0;
            if(isOperator(String.valueOf(currentInput.charAt(currentInput.length() - 1)))) {
                currentInput = currentInput.substring(0, currentInput.length() - 1);
            }else if(String.valueOf(currentInput.charAt(currentInput.length() - 1)).equals(".")){
                currentInput += "0";
            }
        }
        if(input.equals(".")){
            if(pointFlag == 0){
                pointFlag = 1;
                if(currentInput.isEmpty()){
                    currentInput = "0";
                }else if(String.valueOf(currentInput.charAt(currentInput.length() - 1)).equals(".")){
                    currentInput = currentInput.substring(0, currentInput.length() - 1);
                }else if(isOperator(String.valueOf(currentInput.charAt(currentInput.length() - 1)))){
                    currentInput += "0";
                }
            }else{
                return;
            }
        }
        if(input.equals("e")){
            pointFlag = 0;
            if(!currentInput.isEmpty()){
                currentInput += "×";
            }
        }
        currentInput += input;
        resultInput.setText(currentInput);
    }

    private void back( ){
        currentInput = currentInput.substring(0, currentInput.length() - 1);
        if(currentInput.isEmpty()){
            clear();
            return;
        }
        resultInput.setText(currentInput);
    }

    private boolean isNumber(@NonNull String input){
        return input.charAt(0) >= '0' && input.charAt(0) <= '9';
        //return input.equals("0") || input.equals("1") || input.equals("2") || input.equals("3") || input.equals("4") || input.equals("5") || input.equals("6") || input.equals("7") || input.equals("8") || input.equals("9");
    }

    private boolean isOperator(@NonNull String input) {
        return input.equals("+") || input.equals("-") || input.equals("×") || input.equals("÷");
    }

    private void clear() {
        currentInput = "";
        total = 0;
        resultInput.setText("0");
        resultAnswer.setText("0");
    }
}
