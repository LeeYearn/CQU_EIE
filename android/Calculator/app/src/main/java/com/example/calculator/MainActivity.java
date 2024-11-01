package com.example.calculator;

import android.animation.ObjectAnimator;
import android.annotation.SuppressLint;
import android.content.res.Configuration;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewTreeObserver;
import android.widget.Button;
import android.widget.ScrollView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Stack;

public class MainActivity extends AppCompatActivity {
    private TextView resultInput;
    private TextView resultAnswer;
    private TextView resultHistory1;
    private TextView resultHistory2;
    private TextView resultHistory3;
    private Button buttonAC;
    private String currentInput = "";
    private double total = 0;
    private boolean pointFlag = true;
    private int bracketCount = 0;
    private boolean inputTextOverflow = false;
    private boolean overFlag = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.basic);
        defaultView();
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
        resultHistory1 = findViewById(R.id.resultHistory1);
        resultHistory2 = findViewById(R.id.resultHistory2);
        resultHistory3 = findViewById(R.id.resultHistory3);
        buttonAC = findViewById(R.id.buttonAC);

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
        @SuppressLint("SetTextI18n")
        @Override
        public void onClick(@NonNull View v) {
            if (v.getId() == R.id.buttonAC) {
                if(!resultHistory1.getText().toString().isEmpty()&&resultAnswer.getText().toString().equals("0")){
                    resultHistory1.setText("");
                    resultHistory2.setText("");
                    resultHistory3.setText("");
                    buttonAC.setText("AC");
                }
                clear();
                System.out.println("按下了AC");
                encapsulation(0);
            }else if (v.getId() == R.id.buttonEqual) {
                System.out.println("按下了= ");
                if(!currentInput.isEmpty()){
                    AC();
                    encapsulation(1);
                    currentInput = "";
                }
            } else if(v.getId() == R.id.buttonBack){
                System.out.println("按下了Back");
                if(!currentInput.isEmpty()){
                    back();
                    checkTextSize();
                    if(!currentInput.isEmpty()&&isNumber(String.valueOf(currentInput.charAt(currentInput.length() - 1))))calculate();
                }
            }else if(v.getId() == R.id.buttonPercent){
                    System.out.println("按下了%");
                    if(!currentInput.isEmpty()){
                        displayInput("%");
                        calculate();
                }
            }else {
                if(currentInput.isEmpty() && v.getId() == R.id.buttonN0)return;
                displayInput(((Button) v).getText().toString());
                if(isNumber(v)){
                    if(total == 0&&!inputTextOverflow)encapsulation(0);
                    calculate();
                }
            }
            if(!currentInput.isEmpty())buttonAC.setText("C");
//            else if(resultHistory1.getText().toString().isEmpty())

//            System.out.println(currentInput.length());
            System.out.println("resultAnswer.getText().toString()"+resultAnswer.getText().toString());
        }
    }

    private boolean isNumber(@NonNull View v){
        return v.getId()== R.id.buttonPercent || v.getId() == R.id.buttonN1 || v.getId() == R.id.buttonN2 || v.getId() == R.id.buttonN3 || v.getId() == R.id.buttonN4 || v.getId() == R.id.buttonN5 || v.getId() == R.id.buttonN6 || v.getId() == R.id.buttonN7 || v.getId() == R.id.buttonN8 || v.getId() == R.id.buttonN9 || v.getId() == R.id.buttonN0;
    }

    @SuppressLint("SetTextI18n")
    private void calculate() {
        BigDecimal x = BigDecimal.ZERO; // 临时存储数字
        BigDecimal decimalFactor = BigDecimal.ONE; // 用于处理小数部分
        boolean flg = false; // 是否是数字
        boolean isDecimal = false; // 是否正在处理小数
        char lastChar = '\0';// 记录上一个字符，以判断是否是数字
        Stack<BigDecimal> numStack = new Stack<>();
        Stack<Character> opStack = new Stack<>();

        String calculateInput = currentInput + ")".repeat(bracketCount);// 替换所有的%为×0.01并补充右括号
        System.out.println(calculateInput);


        try {
            for (char c : calculateInput.toCharArray()) {
                if (c >= '0' && c <= '9') {
                    if (isDecimal) {
                        decimalFactor = decimalFactor.multiply(BigDecimal.valueOf(0.1)); // 计算小数部分的位置
                        x = x.add(decimalFactor.multiply(BigDecimal.valueOf(c - '0'))); // 将小数部分添加到x中
                    } else {
                        x = x.multiply(BigDecimal.TEN).add(BigDecimal.valueOf(c - '0')); // 处理整数部分
                    }
                    flg = true;
                } else if (c == '.') {
                    if (!isDecimal) {
                        isDecimal = true; // 开始处理小数部分
                    }
                } else if (c == '%') {
                    // 处理百分比，乘以0.01并更新currentInput
                    if (flg) {
                        x = x.multiply(BigDecimal.valueOf(0.01)); // 转换为小数
                        String str = x.stripTrailingZeros().scale() <= 0 ? String.valueOf(x.toBigInteger()) : x.toString();
                        // 更新currentInput
                        String regex = "\\d+%$"; // 匹配以数字和%结尾的部分
                        currentInput = currentInput.replaceAll(regex, str);
                    }
                    // 直接跳过%，不入栈
                    continue;
                } else {
                    if (flg) {
                        numStack.push(x);
                        x = BigDecimal.ZERO; // 重置x
                        decimalFactor = BigDecimal.ONE; // 重置小数因子
                        isDecimal = false; // 重置小数标志
                        flg = false;
                    }

                    // 检查是否在数字后面遇到左括号
                    if (c == '(' && (lastChar >= '0' && lastChar <= '9')) {
                        opStack.push('×'); // 添加乘法操作符
                    }

                    if (c == '(') {
                        opStack.push(c);
                        continue; // 左括号入栈
                    }

                    if (c == ')') {
                        while (!opStack.isEmpty() && opStack.peek() != '(')
                            infixCalc(numStack, opStack);
                        opStack.pop(); // 移除左括号
                        continue;
                    }

                    // 此时c是运算符, 且有运算级更低的, 形如 (a*b+)
                    while (!opStack.isEmpty() && infixLevel(opStack.peek()) >= infixLevel(c))
                        infixCalc(numStack, opStack);
                    opStack.push(c); // 运算符入栈
                }
                lastChar = c;// 更新上一个字符
            }
            if (flg) numStack.push(x);// 最后一个数字
            while (!opStack.isEmpty()) infixCalc(numStack, opStack);// 最后一个运算符
            BigDecimal total = numStack.pop();
            String str = total.stripTrailingZeros().scale() <= 0 ? String.valueOf(total.toBigInteger()) : total.toString();
            resultAnswer.setText("= "+ processNumber(str));
        } catch (Exception e) {
            clear();
            resultAnswer.setText("出错了");
            encapsulation(1);
        }
    }


    private void displayInput(String input) {
        if(currentInput.isEmpty() && isOperator(input) || overFlag){
            System.out.println("没成功输入");
            return;
        }
        defaultView();
        System.out.println("input"+input);
        switch (input) {
            case "+": case "-": case "×": case "÷":
                pointFlag = true;
                if(isOperator(String.valueOf(currentInput.charAt(currentInput.length() - 1)))) {
                    currentInput = currentInput.substring(0, currentInput.length() - 1);
                }else if(String.valueOf(currentInput.charAt(currentInput.length() - 1)).equals(".")){
                    currentInput += "0";
                }
            case ".":
                if (pointFlag) {
                    pointFlag = false;
                    if (currentInput.isEmpty()) {
                        currentInput = "0";
                    } else if (String.valueOf(currentInput.charAt(currentInput.length() - 1)).equals(".")) {
                        currentInput = currentInput.substring(0, currentInput.length() - 1);
                    } else if (isOperator(String.valueOf(currentInput.charAt(currentInput.length() - 1)))) {
                        currentInput += "0";
                    }
                } else return;
                break;
            case "(":
                bracketCount++;
                break;
            case ")":
                if (bracketCount == 0) return;
                bracketCount--;
                break;
            case "e":
                return;
        }
        currentInput += input;
        resultInput.setText(currentInput);
        checkTextSize();
    }

    private void checkTextSize() {
        int width = resultInput.getMeasuredWidth()-60;// 获取当前视图宽度
        float textWidth = resultInput.getPaint().measureText(currentInput);// 获取当前文本宽度，加上一个字符作为预判
        float maxSize = 60.0f; // 默认目标大小
        float minSize = 30.0f; // 最小大小
        float newSize = resultInput.getTextSize() / getResources().getDisplayMetrics().scaledDensity; // 当前大小
        if (textWidth > width) {// 如果文本超出宽度，逐步减小字体大小
            while (textWidth > width) {
                newSize -= 2; // 每次减少2sp
                resultInput.setTextSize(newSize);
                textWidth = resultInput.getPaint().measureText(currentInput); // 重新测量，加入宽字符
            }
            if(newSize <= minSize)overFlag = true;
            inputTextOverflow = true; // 设置标志为true
        } else if (inputTextOverflow) {// 如果宽度在范围内并且之前超出，逐步恢复到目标大小
            while (newSize < maxSize) {
                newSize += 2; // 每次增加2sp
                resultInput.setTextSize(newSize);
                textWidth = resultInput.getPaint().measureText(currentInput); // 重新测量，加入宽字符
                if (textWidth > width)break;// 如果超出，停止增加
            }
            if (newSize >= maxSize) inputTextOverflow = false;// 如果成功恢复到正常范围，则重置标志
        }
    }

    public static String processNumber(String number) {
        if (number == null || number.indexOf('.') == -1) return number; // 如果没有小数点，直接返回原字符串
        int decimalIndex = number.indexOf('.'); // 找到小数点的位置
        if (decimalIndex != -1) {// 从字符串末尾开始，找到小数点后的第一个非零数字
            int nonZeroIndex = number.length() - 1;
            while (nonZeroIndex > decimalIndex && number.charAt(nonZeroIndex) == '0') nonZeroIndex--;
            number = number.substring(0, nonZeroIndex + 1);// 截取从字符串开始到这个非零数字后面的所有字符
        }
        return number;// 构建最终结果并返回
    }

    private void AC(){
//        String history1 = resultHistory1.getText().toString();
//        String history2 = resultHistory1.getText().toString();
        resultHistory3.setText(resultHistory2.getText());
        resultHistory2.setText(resultHistory1.getText());
        String str = resultInput.getText().toString()+" "+resultAnswer.getText().toString();
        resultHistory1.setText(str);
    }

    private void back( ){
        currentInput = currentInput.substring(0, currentInput.length() - 1);
        if(currentInput.isEmpty()){
            clear();
            return;
        }
        if(String.valueOf(currentInput.charAt(currentInput.length() - 1)).equals("("))bracketCount--;
        else if(String.valueOf(currentInput.charAt(currentInput.length() - 1)).equals(")"))bracketCount++;
        overFlag=false;
        resultInput.setText(currentInput);
    }

    private void infixCalc(@NonNull Stack<BigDecimal> numStack, @NonNull Stack<Character> opStack) {
        BigDecimal b = numStack.pop();
        BigDecimal a = numStack.pop();
        char op = opStack.pop();

        switch (op) {
            case '+':
                numStack.push(a.add(b));
                break;
            case '-':
                numStack.push(a.subtract(b));
                break;
            case '×': // 注意修改为你的乘法符号
                numStack.push(a.multiply(b));
                break;
            case '÷': // 注意修改为你的除法符号
                if (b.compareTo(BigDecimal.ZERO) == 0) {
                    throw new ArithmeticException("除以零");
                }
                numStack.push(a.divide(b, 18,RoundingMode.HALF_UP)); // 使用四舍五入处理除法
                break;
            case '^':
                numStack.push(a.pow(b.intValue())); // 取幂
                break;
        }
    }


    private int infixLevel(char a) {
        if (a == '^') return 3;
        if (a == '×' || a == '÷') return 2;
        if (a == '+' || a == '-') return 1;
        return 0; // 括号
    }


    private void encapsulation(int flag){
        if(flag == 1){
            animateTextSize(resultInput, 30, ContextCompat.getColor(MainActivity.this, R.color.text_color3)); // 修改字体大小和颜色
            animateTextSize(resultAnswer, 60, ContextCompat.getColor(MainActivity.this, R.color.text_color1)); // 修改字体大小和颜色
        }else if(flag == 0){
            animateTextSize(resultInput, 60, ContextCompat.getColor(MainActivity.this, R.color.text_color1)); // 修改字体大小和颜色
            animateTextSize(resultAnswer, 30, ContextCompat.getColor(MainActivity.this, R.color.text_color3)); // 修改字体大小和颜色
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

    private boolean isNumber(@NonNull String input) {
        return input.charAt(0)<='9'&&input.charAt(0)>='0';
    }

    private void defaultView(){
        ScrollView scrollView = findViewById(R.id.scrollView); // 假设你的 ScrollView id 是 scrollView
        scrollView.post(new Runnable() {
            @Override
            public void run() {
                scrollView.fullScroll(View.FOCUS_DOWN);
            }
        });
    }

    private void clear() {
        pointFlag=true;
        overFlag = false;
        bracketCount=0;
        inputTextOverflow = false;
        currentInput = "";
        total = 0;
        resultInput.setText("0");
        resultAnswer.setText("0");
    }
}