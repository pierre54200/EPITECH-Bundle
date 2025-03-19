FROM maven:3.9.6-eclipse-temurin-21-alpine AS builder
WORKDIR /app
COPY . /app
RUN mvn dependency:resolve
RUN mvn package

FROM eclipse-temurin:21-jre-alpine
WORKDIR /app
COPY --from=builder /app/target/worker-jar-with-dependencies.jar /app/worker-jar-with-dependencies.jar
EXPOSE 80
CMD ["java", "-jar", "/app/worker-jar-with-dependencies.jar"]