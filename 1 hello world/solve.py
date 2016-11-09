
import argparse
import angr


def main(args):

    print("Starting with args {}".format(str(args)))

    proj = angr.Project(args.file)
    print("Loaded Project: {}".format(proj))

    pg = proj.factory.path_group(save_unconstrained=True)
    
    while len(pg.active) > 0:
        pg.step()

    #import IPython; IPython.embed()


if __name__ == "__main__":
    options = [
        (("-f", "--file"), {"required": True}),
        (("-v", "--verbose"), {"required": False, "action": "store_true",
            "default": False})
    ]
    ap = argparse.ArgumentParser()
    for arg, kwarg in options:
        ap.add_argument(*arg, **kwarg)
    main(ap.parse_args())
