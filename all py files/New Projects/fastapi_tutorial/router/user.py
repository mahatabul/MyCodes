from fastapi import APIRouter, Request
from controller.user import register, get_user
from models.user import UserSchema, UserResponse

router = APIRouter(prefix="/users",tags=["items"])


@router.get("/login")
def get_user_route():
    return get_user()

@router.post("/register",response_model=UserResponse)
def create_user_route(user ,request: Request):
    return register(request)


