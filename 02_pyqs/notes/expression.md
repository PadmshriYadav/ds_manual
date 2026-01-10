# Stack & Expression Notations

## 1. Expression Notations: Infix, Prefix, & Postfix

These are three fundamental ways to write binary mathematical expressions, differing based on the relative position of the **operator** with respect to its **operands**.

| Notation | Operator Position | Example (A + B) | Evaluation Method |
| :---: | :---: | :---: | :---: |
| **Infix** | **In** between operands | A + B | Rules of **Precedence** and **Parentheses**. |
| **Prefix** | **Pre**cedes operands | + A B | **Stack** (Scanned **Right-to-Left**). |
| **Postfix** | Comes **after** operands | A B + | **Stack** (Scanned **Left-to-Right**). |

---

## 2. Infix Notation (Human Readable)

* **Format:** `<Operand> <Operator> <Operand>` (e.g., A + B)
* **Key Feature:** It is the standard, natural way humans write math.
* **Challenge:** It is **ambiguous** for computers. To resolve the order of operations, it **requires**:
    * **Parentheses:** To explicitly group operations (e.g., (A + B) * ).
    * **Operator Precedence Rules:** (e.g., Multiplication/Division before Addition/Subtraction, commonly known as **BODMAS**).

---

## 3. Prefix Notation (Polish Notation)

* **Format:** `<Operator> <Operand> <Operand>` (e.g., + A B)
* **Key Feature:** The order of operations is **uniquely determined** by the position of the tokens.
* **Advantage:** **No parentheses** or precedence rules are needed.
* **Complex Example:** * + A B C$ (Represents (A + B) * C)

---

## 4. Postfix Notation (Reverse Polish Notation or RPN)

* **Format:** `<Operand> <Operand> <Operator>` (e.g., A B +)
* **Key Feature:** Ideal for computer processing, specifically with a **Stack** data structure.
* **Advantage:** **No parentheses** or precedence rules are needed. Operators appear *after* the operands they operate on.
* **Complex Example:** A B + C * (Represents (A + B) * C)

---

## Concept: The Role of the Stack

* **Infix --> Postfix/Prefix Conversion:** A stack is used to temporarily hold operators and manage their precedence correctly.
* **Evaluation (Postfix/Prefix):** A stack is used to hold operands until an operator is encountered. The operator then performs the calculation on the required number of operands popped from the stack, and the result is pushed back.


##  Conversion: Infix --> Postfix

This algorithm scans the **Infix** expression **left-to-right** and uses an **operator stack** to correctly manage precedence.

| Token Read | Action |
| :--- | :--- |
| **Operand** (Variable, Number) | **Append** it immediately to the Postfix output. |
| **Open Parenthesis** `(` | **Push** it onto the operator stack. |
| **Close Parenthesis** `)` | **Pop** operators from the stack and **append** them to the output until a matching `(` is encountered. **Discard** both parentheses. |
| **Operator** ($\mathbf{+,-,*,/,\wedge}$) | 1. While the stack is **NOT** empty, the top element is **NOT** `(`, AND the top operator has **Higher or Equal Precedence** than the current operator: **Pop** the stack top and **append** it to the output. 2. **Push** the current operator onto the stack. |
| **End of Expression** | **Pop** any remaining operators from the stack and **append** them to the output. |

---

##  Evaluation: Postfix Expression (Reverse Polish Notation - RPN)

This algorithm scans the **Postfix** expression **left-to-right** using an **operand stack**.

| Token Read (Left $\rightarrow$ Right) | Action |
| :--- | :--- |
| **Operand** (Number) | **Push** its value onto the operand stack. |
| **Operator** ($\mathbf{+,-,*,/,\wedge}$) | 1. **Pop** the top element: This is **Operand 2 ($O_2$)**. 2. **Pop** the new top element: This is **Operand 1 ($O_1$)**. 3. Calculate the result: **$O_1$ Operator $O_2$**. 4. **Push** the result back onto the stack. |
| **End of Expression** | The single value remaining on the stack is the final result. |

---

##  Evaluation: Prefix Expression (Polish Notation)

This algorithm scans the **Prefix** expression **right-to-left** using an **operand stack**.

| Token Read (Right $\rightarrow$ Left) | Action |
| :--- | :--- |
| **Operand** (Number) | **Push** its value onto the operand stack. |
| **Operator** ($\mathbf{+,-,*,/,\wedge}$) | 1. **Pop** the top element: This is **Operand 1 ($O_1$)**. 2. **Pop** the new top element: This is **Operand 2 ($O_2$)**. 3. Calculate the result: **$O_1$ Operator $O_2$**. 4. **Push** the result back onto the stack. |
| **End of Expression** | The single value remaining on the stack is the final result. |

---