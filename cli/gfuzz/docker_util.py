
import pathlib
import subprocess


def check_docker():
    """Check if docker is available as a shell command."""
    r = subprocess.run('docker -v', shell=True, stdout=subprocess.PIPE, 
        stderr=subprocess.PIPE)

    output = r.stdout.decode('ascii')
    if 'Docker version' in output:
        return

    print('Error: docker not found on path')
    exit(-1)


def build_image(path: pathlib.Path, tag: str):
    """Build a docker image.
    
    Args:
    - path: Path to a folder with a Dockerfile.
    - tag: Name to use as a tag.
    """
    r = subprocess.run(
        f'docker build {path} -t {tag}', 
        shell=True)

    if r.returncode != 0:
        print('Error building image')
        exit(-1)


def run_image(tag: str, cmd: str, volumes: dict = {}, inner_args: str = '', run_args: str = ''):
    """Run a command in a docker image."""

    volume_str = ' '.join(
        f'-v {k}:{volumes[k]}' for k in volumes
    )

    r = subprocess.run(
        f'docker run {volume_str} {run_args} -it {tag} {cmd} {inner_args}', 
        shell=True)
