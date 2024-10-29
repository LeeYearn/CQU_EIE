package com.example.calculator;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    private TextView resultInput;
    private TextView resultAnswer;
    private String currentInput = "";
    private String operator = "";
    private double firstOperand = 0;

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
                R.id.buttonN0, R.id.buttonN1, R.id.buttonN2, R.id.buttonN3,
                R.id.buttonN4, R.id.buttonN5, R.id.buttonN6, R.id.buttonN7,
                R.id.buttonN8, R.id.buttonN9, R.id.buttonAdd, R.id.buttonSub,
                R.id.buttonMulti, R.id.buttonDiv, R.id.buttonEqual, R.id.buttonAC
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
            } else if (v.getId() == R.id.buttonEqual) {
                calculate();
            } else {
                handleInput(((Button) v).getText().toString());
            }
        }
    }

    private void handleInput(String input) {
        // 如果是运算符
        if ("+".equals(input) || "-".equals(input) || "×".equals(input) || "÷".equals(input)) {
            if (!currentInput.isEmpty()) {
                firstOperand = Double.parseDouble(currentInput);
                operator = input;

                // 在输入框中显示当前的操作数和运算符
                String str = firstOperand + " " + operator + " ";
                resultInput.setText(str);
                currentInput = "";  // 清空当前输入以准备下一个数字
            }
        } else if("=".equals(input)) {
            // 处理数字输入
            if (currentInput.isEmpty()) {
                // 如果当前输入为空，直接设置为输入的数字
                currentInput = input;
                resultInput.setText(currentInput);
            } else {
                // 否则拼接输入的数字
                currentInput += input;
                // 显示当前输入
                String str = resultInput.getText().toString() + input;
                resultInput.setText(str);
            }
        }
    }


    private void calculate() {
        if (!currentInput.isEmpty() && !operator.isEmpty()) {
            double secondOperand = Double.parseDouble(currentInput);
            double result;

            switch (operator) {
                case "+":
                    result = firstOperand + secondOperand;
                    break;
                case "-":
                    result = firstOperand - secondOperand;
                    break;
                case "×":
                    result = firstOperand * secondOperand;
                    break;
                case "÷":
                    if (secondOperand != 0) {
                        result = firstOperand / secondOperand;
                    } else {
                        String str = "Error";
                        resultAnswer.setText(str); // 处理除以零的情况
                        return;
                    }
                    break;
                default:
                    return;
            }

            // 显示结果
            resultAnswer.setText(String.valueOf(result));
            // 准备下一次输入
            currentInput = "";
            operator = "";
            //resultInput.setText("0");  // 清空输入框
        }
    }


    private void clear() {
        currentInput = "";
        operator = "";
        resultInput.setText("0");
        resultAnswer.setText("0");
    }
}
