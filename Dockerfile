FROM gcc:latest
WORKDIR /app
COPY main.cpp .
RUN g++ main.cpp -o program
RUN echo "5 2 9 1 7 3" > input.txt
CMD ["sh", "-c", "./program input.txt && cat out.txt"]
