package com.slipknisha;

import com.slipknisha.count.Counter;

public class Main {

    public static void printAuthorInformation() {
        System.out.print("\nAuthor: Vladyslav Bobrykov\n" +
                "2 course of Computer Science, group 201\n" +
                "Embedded Hardware/Software Engineer at Lemberg Solutions Limited\n" +
                "https://github.com/slipknosha\n" +
                "https://www.linkedin.com/in/vladyslav-bobrykov/");
    }

    public static void main(String[] args) {
        Counter counter;
        if (args.length > 0) {
            counter = new Counter(args[0]);
        } else {
            counter = new Counter();
        }
        counter.print();
        counter.printCoding();
        counter.printCode();
        printAuthorInformation();
    }
}