# REGISTER
# curl -i -X POST http://localhost:3000/register \
#   -H "Content-Type: application/json" \
#   -d '{
#     "email":     "julian.hemmer@epitech.eu",
#     "name":      "HEMMER",
#     "firstname": "Julian",
#     "password":  "3paulbed"
#   }'

echo LOGIN
echo
result=$(
    curl -X POST http://localhost:3000/login \
        -H "Content-Type: application/json" \
        -d '{
            "email":     "julian.hemmer@epitech.eu",
            "password":  "3paulbed"
        }'
)

token=$(echo $result | jq .token)
token=$(echo -n "$token" | tail -c +2 | head -c -1)

# # USER INFO [SELF]
# curl -X GET http://localhost:3000/user \
#     -H "Content-Type: application/json" \
#     -H "Authorization: Bearer $token"   \
#     -d '{
#         "email":     "julian.hemmer@epitech.eu",
#         "password":  "3paulbed"
#     }'

# curl -X POST http://localhost:3000/todos \
#     -H "Content-Type: application/json" \
#     -d '{
#         "title": "Je suis le 1",
#         "description": "Complete the math assignment",
#         "due_time": "2025-05-15 18:00:00",
#         "user_id": 1,
#         "status": "todo"
#     }'


# curl -X GET http://localhost:3000/user/todos \
#     -H "Content-Type: application/json" \
#     -H "Authorization: Bearer $token"   

# curl -X PUT http://localhost:3000/todos/27 \
#     -H "Content-Type: application/json" \
#     -d '{
#         "title": "Je suis le 1 mais cahnger",
#         "description": "Complete the math assignment",
#         "due_time": "2025-05-15 18:00:00",
#         "user_id": 1,
#         "status": "todo"
#     }'

# max_id=30
# for id in $(seq 1 $max_id); do
#     echo "🗑️ Suppression du todo ID: $id"
#     curl -s -X DELETE http://localhost:3000/todos/$id \
#         -H "Content-Type: application/json" \
#         -H "Authorization: Bearer Bearer $token"
#     echo -e "\n---"
# done
=======
echo USER INFO [SELF]
curl -X GET http://localhost:3000/user \
    -H "Content-Type: application/json" \
    -H "Authorization: Bearer $token"
echo

exit 1

echo
echo USER INFO [ID: 3]
curl -X GET http://localhost:3000/users/3 \
    -H "Content-Type: application/json" \
    -H "Authorization: Bearer $token"
echo

echo
echo USER INFO [EMAIL: julian.hemmer@epitech.eu]
curl -X GET http://localhost:3000/users/julian.hemmer@epitech.eu \
    -H "Content-Type: application/json" \
    -H "Authorization: Bearer $token"
echo

echo
echo USER INFO [Target: feur]
curl -X GET http://localhost:3000/users/feur \
    -H "Content-Type: application/json" \
    -H "Authorization: Bearer $token"
echo



######################################

curl -X POST http://localhost:3000/register \
        -H "Content-Type: application/json" \
        -d '{
            "email":     "user_to_delete@epitech.eu",
            "name":      "USER",
            "firstname": "DELETE",
            "password":  "zinzindelespace"
        }'

result=$(
    curl -X POST http://localhost:3000/login \
        -H "Content-Type: application/json" \
        -d '{
            "email":     "user_to_delete@epitech.eu",
            "password":  "zinzindelespace"
        }'
)

token=$(echo $result | jq .token)
token=$(echo -n "$token" | tail -c +2 | head -c -1)

echo TOKEN: $token

result=$(
    curl -X GET http://localhost:3000/users/user_to_delete@epitech.eu \
        -H "Content-Type: application/json" \
        -H "Authorization: Bearer $token"
)

id=$(echo $result | jq .id)
echo ID: \'$id\'

echo
echo USER [DELETE: $id]
curl -X DELETE http://localhost:3000/users/$id \
    -H "Content-Type: application/json" \
    -H "Authorization: Bearer $token"
echo

echo
echo USER INFO [ID: $id]
curl -X GET http://localhost:3000/users/$id \
    -H "Content-Type: application/json" \
    -H "Authorization: Bearer $token"
echo

######################################

curl -X POST http://localhost:3000/register \
        -H "Content-Type: application/json" \
        -d '{
            "email":     "some_email@epitech.eu",
            "name":      "USER",
            "firstname": "TEST",
            "password":  "zinzindelespace"
        }'

result=$(
    curl -X POST http://localhost:3000/login \
        -H "Content-Type: application/json" \
        -d '{
            "email":     "some_email@epitech.eu",
            "password":  "zinzindelespace"
        }'
)

token=$(echo $result | jq .token)
token=$(echo -n "$token" | tail -c +2 | head -c -1)

echo TOKEN: $token

result=$(
    curl -X GET http://localhost:3000/users/some_email@epitech.eu \
        -H "Content-Type: application/json" \
        -H "Authorization: Bearer $token"
)

id=$(echo $result | jq .id)
echo ID: \'$id\'

echo
echo USER [PUT: $id]
curl -X PUT http://localhost:3000/users/$id \
    -H "Content-Type: application/json" \
    -H "Authorization: Bearer $token"  \
    -d '{
            "email":     "other_email@epitech.eu",
            "password":  "new_password",
            "firstname":  "RANDOM",
            "name":  "NAME"
        }'
echo
echo USER INFO [ID: $id]
curl -X GET http://localhost:3000/users/$id \
    -H "Content-Type: application/json" \
    -H "Authorization: Bearer $token"
echo

echo
echo USER [DELETE: $id]
curl -X DELETE http://localhost:3000/users/$id \
    -H "Content-Type: application/json" \
    -H "Authorization: Bearer $token"
echo
